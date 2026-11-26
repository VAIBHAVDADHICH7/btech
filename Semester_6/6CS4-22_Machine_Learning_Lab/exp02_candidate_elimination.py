# Exp 2: Candidate-Elimination Algorithm
import csv
from pathlib import Path

csv_path = Path(__file__).parent / "enjoysport.csv"
with open(csv_path, newline="") as f:
    rows = list(csv.reader(f))[1:]

n_attr = len(rows[0]) - 1
S = ["0"] * n_attr
G = [["?"] * n_attr]

for row in rows:
    x, label = row[:-1], row[-1]
    if label.lower() == "yes":
        G = [g for g in G if all(gv == "?" or gv == xv for gv, xv in zip(g, x))]
        for i in range(n_attr):
            if S[i] == "0": S[i] = x[i]
            elif S[i] != x[i]: S[i] = "?"
    else:
        new_G = []
        for g in G:
            if all(gv == "?" or gv == xv for gv, xv in zip(g, x)):
                for i in range(n_attr):
                    if g[i] == "?" and S[i] != "?" and S[i] != x[i]:
                        h = list(g); h[i] = S[i]
                        new_G.append(h)
            else:
                new_G.append(g)
        G = new_G

print("Final Specific Boundary S:", S)
print("Final General Boundary  G:", G)
