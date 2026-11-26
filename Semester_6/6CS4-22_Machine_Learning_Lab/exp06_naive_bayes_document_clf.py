# Exp 6: Multinomial Naive Bayes Document Classification (Accuracy, Precision, Recall)
import math
from collections import Counter

docs = [
    ("I love this movie it is fantastic", "pos"),
    ("Great acting and wonderful story", "pos"),
    ("Terrible film waste of time", "neg"),
    ("Awful plot and boring scenes", "neg"),
]
test = [
    ("Wonderful movie I love it", "pos"),
    ("Boring and terrible film", "neg"),
]

vocab = set(w.lower() for text, _ in docs for w in text.split())
counts = {"pos": Counter(), "neg": Counter()}
totals = {"pos": 0, "neg": 0}
for text, label in docs:
    for w in text.lower().split():
        counts[label][w] += 1
        totals[label] += 1

def classify(text):
    words = text.lower().split()
    best_lbl, best_score = None, -1e9
    for lbl in ("pos", "neg"):
        score = math.log(0.5)
        for w in words:
            score += math.log((counts[lbl][w] + 1) / (totals[lbl] + len(vocab)))
        if score > best_score:
            best_score, best_lbl = score, lbl
    return best_lbl

tp = fp = fn = tn = 0
for text, truth in test:
    pred = classify(text)
    if pred == "pos" and truth == "pos": tp += 1
    elif pred == "pos" and truth == "neg": fp += 1
    elif pred == "neg" and truth == "pos": fn += 1
    else: tn += 1

acc = (tp + tn) / len(test)
prec = tp / (tp + fp) if (tp + fp) else 0
rec = tp / (tp + fn) if (tp + fn) else 0
print(f"Accuracy={acc:.2f}, Precision={prec:.2f}, Recall={rec:.2f}")
