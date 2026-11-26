# Exp 6: Character Frequency Dictionary & Birthday Lookup using split/join
text = "engineering"
freq = {}
for ch in text:
    freq[ch] = freq.get(ch, 0) + 1
print("Char frequencies:", freq)

birthdays = {"Aarav": "14/08/2004", "Diya": "22/11/2003"}
name = "Aarav"
parts = birthdays[name].split("/")
print(f"{name}'s birthday:", "-".join(parts))
