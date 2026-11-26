# Exp 5: Gaussian Naive Bayes Classifier from Scratch
import numpy as np

X_train = np.array([[1.0, 2.1], [1.2, 1.9], [5.0, 5.2], [5.3, 4.8]])
y_train = np.array([0, 0, 1, 1])
X_test = np.array([[1.1, 2.0], [5.1, 5.0]])
y_test = np.array([0, 1])

classes = np.unique(y_train)
stats = {c: (X_train[y_train == c].mean(axis=0), X_train[y_train == c].var(axis=0) + 1e-6) for c in classes}

def predict(X):
    preds = []
    for x in X:
        scores = {}
        for c, (mu, var) in stats.items():
            log_prob = -0.5 * np.sum(np.log(2 * np.pi * var) + ((x - mu) ** 2) / var)
            scores[c] = log_prob
        preds.append(max(scores, key=scores.get))
    return np.array(preds)

preds = predict(X_test)
print("Predictions:", preds, "| Accuracy:", (preds == y_test).mean())
