# Lab Project: Secure P2P File Transfer (Server & Client over TCP with Auth + Encryption)
import hashlib, hmac, os, socket, sys

SHARED_KEY = b"rtu_lan_p2p_shared_secret_key_256"

def xor_stream(data: bytes, nonce: bytes) -> bytes:
    out = bytearray()
    counter = 0
    while len(out) < len(data):
        block = hashlib.sha256(SHARED_KEY + nonce + counter.to_bytes(4, "big")).digest()
        out.extend(block)
        counter += 1
    return bytes(a ^ b for a, b in zip(data, out))

def run_server(port=9090):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind(("0.0.0.0", port)); s.listen(1)
        print(f"Secure P2P Receiver listening on port {port}...")
        conn, _ = s.accept()
        with conn:
            payload = conn.recv(1024 * 1024)
            nonce, tag, ct = payload[:16], payload[16:48], payload[48:]
            if hmac.compare_digest(tag, hmac.new(SHARED_KEY, nonce + ct, hashlib.sha256).digest()):
                data = xor_stream(ct, nonce)
                with open("received_secure_file.bin", "wb") as f: f.write(data)
                print("Authenticated & decrypted file saved (bytes):", len(data))
            else:
                print("Authentication failed! File rejected.")

def run_client(host, port, filepath):
    raw = open(filepath, "rb").read()
    nonce = os.urandom(16)
    ct = xor_stream(raw, nonce)
    tag = hmac.new(SHARED_KEY, nonce + ct, hashlib.sha256).digest()
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((host, port))
        s.sendall(nonce + tag + ct)
    print("Encrypted & signed file sent successfully.")

if __name__ == "__main__":
    if len(sys.argv) >= 2 and sys.argv[1] == "server":
        run_server()
    elif len(sys.argv) == 4 and sys.argv[1] == "client":
        run_client(sys.argv[2], 9090, sys.argv[3])
    else:
        print("Usage: python3 lab_project_secure_p2p_file_transfer.py server | client <host> <file>")
