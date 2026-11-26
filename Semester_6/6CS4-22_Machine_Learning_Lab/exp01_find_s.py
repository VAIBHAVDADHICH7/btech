# Exp 1: FIND-S Algorithm
import csv
from pathlib import Path

csv_path = Path(__file__).parent / "enjoysport.csv"
with open(csv_path, newline="") as f:
    rows = list(csv.reader(f))[1:]

h = None
for row in rows:
    features, label = row[:-1], row[-1]
    if label.lower() == "yes":
        if h is None:
            h = list(features)
        else:
            h = [hv if hv == fv else "?" for hv, fv in zip(h, features)]

print("Most Specific Hypothesis (FIND-S):", h)
