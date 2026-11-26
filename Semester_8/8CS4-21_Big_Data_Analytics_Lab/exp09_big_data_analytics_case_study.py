# Exp 9: Real-Life Big Data Analytics Problem — E-Commerce Clickstream MapReduce Simulation
from collections import defaultdict

logs = [
    ("2026-11-01", "Jaipur", "Electronics", 15999),
    ("2026-11-01", "Delhi", "Books", 499),
    ("2026-11-02", "Jaipur", "Electronics", 24999),
    ("2026-11-02", "Mumbai", "Apparel", 1999),
]

# Map phase
mapped = [((city, cat), amt) for _, city, cat, amt in logs]
# Shuffle & Reduce phase
totals = defaultdict(int)
for key, val in mapped:
    totals[key] += val

for (city, cat), rev in sorted(totals.items(), key=lambda x: -x[1]):
    print(f"{city:<8} | {cat:<12} | Revenue: Rs.{rev}")
