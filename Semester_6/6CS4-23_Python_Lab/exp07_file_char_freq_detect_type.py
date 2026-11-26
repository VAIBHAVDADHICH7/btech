# Exp 7: Character Frequency in File & File Type Detection
from collections import Counter
from pathlib import Path

p = Path(__file__)
content = p.read_text(encoding="utf-8")
freq = Counter(content)
if p.suffix == ".py": ftype = "Python file"
elif p.suffix == ".c": ftype = "C file"
else: ftype = "Text file"
print(f"File: {p.name} ({ftype}) | Top 5 chars:", freq.most_common(5))
