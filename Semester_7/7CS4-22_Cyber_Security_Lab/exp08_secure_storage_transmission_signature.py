# Exp 8: Authenticated Encryption & Digital Signature Demonstration (HMAC-SHA256 + Stream Keystream)
import hashlib, hmac, os

key = b"super_secret_lab_key_32bytes_min!"
plaintext = b"Confidential BTech Lab Record"
nonce = os.urandom(16)

# Derive keystream from SHA-256(key || nonce)
keystream = hashlib.sha256(key + nonce).digest()
ciphertext = bytes(p ^ k for p, k in zip(plaintext, keystream))
signature = hmac.new(key, nonce + ciphertext, hashlib.sha256).hexdigest()

# Verify & Decrypt
valid = hmac.compare_digest(signature, hmac.new(key, nonce + ciphertext, hashlib.sha256).hexdigest())
recovered = bytes(c ^ k for c, k in zip(ciphertext, hashlib.sha256(key + nonce).digest()))
print("Signature Valid:", valid, "| Decrypted:", recovered.decode())
