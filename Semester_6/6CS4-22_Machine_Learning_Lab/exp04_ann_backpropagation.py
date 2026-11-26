# Exp 4: Artificial Neural Network with Backpropagation (XOR)
import numpy as np

X = np.array([[0,0],[0,1],[1,0],[1,1]], dtype=float)
y = np.array([[0],[1],[1],[0]], dtype=float)

rng = np.random.default_rng(42)
W1 = rng.normal(0, 1, (2, 4))
b1 = np.zeros((1, 4))
W2 = rng.normal(0, 1, (4, 1))
b2 = np.zeros((1, 1))

sigmoid = lambda z: 1.0 / (1.0 + np.exp(-z))
dsigmoid = lambda a: a * (1.0 - a)

lr = 0.5
for _ in range(5000):
    h = sigmoid(X @ W1 + b1)
    out = sigmoid(h @ W2 + b2)
    d_out = (y - out) * dsigmoid(out)
    d_h = (d_out @ W2.T) * dsigmoid(h)
    W2 += h.T @ d_out * lr
    b2 += d_out.sum(axis=0, keepdims=True) * lr
    W1 += X.T @ d_h * lr
    b1 += d_h.sum(axis=0, keepdims=True) * lr

print("XOR Predictions:", np.round(out.ravel(), 3))
