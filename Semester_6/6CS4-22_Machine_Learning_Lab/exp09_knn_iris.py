# Exp 9: k-Nearest Neighbour (k-NN) Classifier (Iris-style 3-Class Dataset)
import numpy as np
from collections import Counter

# Sample Iris-like measurements: [sepal_len, sepal_wid, petal_len, petal_wid]
X_train = np.array([
    [5.1,3.5,1.4,0.2],[4.9,3.0,1.4,0.2],[5.0,3.4,1.5,0.2],
    [7.0,3.2,4.7,1.4],[6.4,3.2,4.5,1.5],[6.9,3.1,4.9,1.5],
    [6.3,3.3,6.0,2.5],[5.8,2.7,5.1,1.9],[7.1,3.0,5.9,2.1]
])
y_train = ["Setosa"]*3 + ["Versicolor"]*3 + ["Virginica"]*3

X_test = np.array([[5.0,3.6,1.4,0.2], [6.5,3.0,4.6,1.5], [6.5,3.0,5.8,2.2]])
y_test = ["Setosa", "Versicolor", "Virginica"]

def knn_predict(x, k=3):
    dists = np.linalg.norm(X_train - x, axis=1)
    idx = np.argsort(dists)[:k]
    return Counter(y_train[i] for i in idx).most_common(1)[0][0]

for x, truth in zip(X_test, y_test):
    pred = knn_predict(x, k=3)
    status = "CORRECT" if pred == truth else "WRONG"
    print(f"Actual: {truth:<10} | Predicted: {pred:<10} -> {status}")
