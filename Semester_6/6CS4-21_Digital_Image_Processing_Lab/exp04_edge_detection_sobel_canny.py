# Exp 4: Edge Detection (Sobel & Canny) on Noisy Image
import numpy as np
import cv2

img = np.zeros((128, 128), dtype=np.uint8)
cv2.rectangle(img, (32, 32), (96, 96), 220, -1)
rng = np.random.default_rng(42)
noisy = np.clip(img.astype(np.int16) + rng.normal(0, 15, img.shape), 0, 255).astype(np.uint8)

sobelx = cv2.Sobel(noisy, cv2.CV_64F, 1, 0, ksize=3)
sobely = cv2.Sobel(noisy, cv2.CV_64F, 0, 1, ksize=3)
sobel_mag = np.hypot(sobelx, sobely)
canny = cv2.Canny(noisy, 80, 160)

print(f"Sobel edge pixels (>100): {(sobel_mag > 100).sum()} | Canny edge pixels: {(canny > 0).sum()}")
