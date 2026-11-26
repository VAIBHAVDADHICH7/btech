# Exp 1: Substitution (Caesar Cipher) & Transposition (Rail Fence Cipher)
def caesar(text: str, shift: int) -> str:
    res = []
    for ch in text:
        if ch.isalpha():
            base = ord("A") if ch.isupper() else ord("a")
            res.append(chr((ord(ch) - base + shift) % 26 + base))
        else:
            res.append(ch)
    return "".join(res)

def rail_fence_encrypt(text: str, rails: int) -> str:
    fence = [[] for _ in range(rails)]
    rail, step = 0, 1
    for ch in text:
        fence[rail].append(ch)
        if rail == 0: step = 1
        elif rail == rails - 1: step = -1
        rail += step
    return "".join("".join(r) for r in fence)

msg = "CYBERSECURITY"
enc_c = caesar(msg, 3)
print("Caesar Enc:", enc_c, "| Dec:", caesar(enc_c, -3))
print("Rail Fence (3 rails):", rail_fence_encrypt(msg, 3))
