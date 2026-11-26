# Exp 3: ID3 Decision Tree Classifier
import math
from collections import Counter

data = [
    {"Outlook": "Sunny", "Humidity": "High", "Play": "No"},
    {"Outlook": "Sunny", "Humidity": "Normal", "Play": "Yes"},
    {"Outlook": "Overcast", "Humidity": "High", "Play": "Yes"},
    {"Outlook": "Rain", "Humidity": "High", "Play": "Yes"},
    {"Outlook": "Rain", "Humidity": "Normal", "Play": "No"},
]

def entropy(rows):
    counts = Counter(r["Play"] for r in rows)
    total = len(rows)
    return -sum((c / total) * math.log2(c / total) for c in counts.values())

def id3(rows, attrs):
    labels = [r["Play"] for r in rows]
    if len(set(labels)) == 1: return labels[0]
    if not attrs: return Counter(labels).most_common(1)[0][0]
    base_ent = entropy(rows)
    best_attr = max(attrs, key=lambda a: base_ent - sum(
        (len(sub) / len(rows)) * entropy(sub)
        for v in set(r[a] for r in rows)
        for sub in [[r for r in rows if r[a] == v]]
    ))
    tree = {best_attr: {}}
    for v in set(r[best_attr] for r in rows):
        sub = [r for r in rows if r[best_attr] == v]
        tree[best_attr][v] = id3(sub, [a for a in attrs if a != best_attr])
    return tree

tree = id3(data, ["Outlook", "Humidity"])
print("ID3 Decision Tree:", tree)
