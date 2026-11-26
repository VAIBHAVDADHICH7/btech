# Exp 10: Non-Parametric Locally Weighted Regression (LWR)
import numpy as np

X = np.linspace(0, 2 * np.pi, 40)
y = np.sin(X) + 0.1 * np.cos(3 * X)
tau = 0.5

def lwr_predict(x0):
    W = np.diag(np.exp(-((X - x0) ** 2) / (2 * tau ** 2)))
    Xb = np.column_stack([np.ones_like(X), X])
    theta = np.linalg.pinv(Xb.T @ W @ Xb) @ (Xb.T @ W @ y)
    return float(theta[0] + theta[1] * x0)

preds = [lwr_predict(x0) for x0 in [0.5, 1.5, 3.0, 5.0]]
for x0, p in zip([0.5, 1.5, 3.0, 5.0], preds):
    print(f"x={x0:.1f} -> True={np.sin(x0):.3f}, LWR Pred={p:.3f}")
