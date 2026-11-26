# Exp 3: Loops, ZeroDivisionError, Time Intervals, File Line Word Count
import time
from pathlib import Path

for i in range(3):
    print(f"[for] IoT Lab #{i+1}")

k = 0
while k < 2:
    print(f"[while] IoT Lab #{k+1}")
    k += 1

try:
    _ = 10 / 0
except ZeroDivisionError as e:
    print("Handled ZeroDivisionError:", e)

# Print current time (demo uses 2 iterations of 0.1s; set range(10) and sleep(10) on Pi)
for _ in range(2):
    print("Current Time:", time.strftime("%H:%M:%S"))
    time.sleep(0.1)

for idx, line in enumerate(Path(__file__).read_text(encoding="utf-8").splitlines()[:5], 1):
    print(f"Line {idx}: {len(line.split())} words")
