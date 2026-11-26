# Exp 3: Educational Local Password Strength Audit (Dictionary & Short Brute-Force Demo)
# Runs strictly against a local SHA-256 test hash to illustrate why weak passwords fail.
import hashlib, itertools, string

target_hash = hashlib.sha256(b"pass123").hexdigest()
wordlist = ["admin", "qwerty", "pass123", "welcome"]
found_dict = next((w for w in wordlist if hashlib.sha256(w.encode()).hexdigest() == target_hash), None)
print("Local Dictionary Audit Match:", found_dict)

pin_hash = hashlib.sha256(b"042").hexdigest()
found_pin = None
for tup in itertools.product(string.digits, repeat=3):
    cand = "".join(tup)
    if hashlib.sha256(cand.encode()).hexdigest() == pin_hash:
        found_pin = cand
        break
print("Local 3-Digit PIN Audit Match:", found_pin)
