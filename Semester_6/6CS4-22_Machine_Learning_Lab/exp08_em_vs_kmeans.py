# Exp 8: k-Means vs Expectation-Maximization (2D GMM) Clustering
import numpy as np

rng = np.random.default_rng(0)
X = np.vstack([rng.normal([0, 0], 0.6, (30, 2)), rng.normal([4, 4], 0.6, (30, 2))])

# k-Means (k=2)
centroids = X[[0, 35]].copy()
for _ in range(20):
    dists = np.linalg.norm(X[:, None, :] - centroids[None, :, :], axis=2)
    labels_km = dists.argmin(axis=1)
    for k in range(2):
        centroids[k] = X[labels_km == k].mean(axis=0)

# EM (2-component diagonal Gaussian Mixture)
means = X[[1, 36]].copy()
vars_ = np.ones((2, 2))
pis = np.array([0.5, 0.5])
for _ in range(30):
    resp = np.zeros((len(X), 2))
    for k in range(2):
        coef = 1.0 / np.sqrt(np.prod(2 * np.pi * vars_[k]))
        resp[:, k] = pis[k] * coef * np.exp(-0.5 * np.sum(((X - means[k]) ** 2) / vars_[k], axis=1))
    resp /= resp.sum(axis=1, keepdims=True)
    nk = resp.sum(axis=0)
    pis = nk / len(X)
    for k in range(2):
        means[k] = (resp[:, k:k+1] * X).sum(axis=0) / nk[k]
        vars_[k] = (resp[:, k:k+1] * (X - means[k]) ** 2).sum(axis=0) / nk[k] + 1e-4

labels_em = resp.argmax(axis=1)
print("k-Means centroids:\n", np.round(centroids, 2))
print("EM GMM means:\n", np.round(means, 2))
print("Cluster agreement:", round(float((labels_km == labels_em).mean()), 3))
