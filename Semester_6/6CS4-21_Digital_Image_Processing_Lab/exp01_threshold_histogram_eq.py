# Exp 1: Thresholding & Histogram Equalization
import numpy as np
import cv2

img = np.tile(np.linspace(40, 210, 256, dtype=np.uint8), (256, 1))
_, thresh = cv2.threshold(img, 127, 255, cv2.THRESH_BINARY)
eq = cv2.equalizeHist(img)
hist_orig = cv2.calcHist([img], [0], None, [256], [0, 256])
hist_eq = cv2.calcHist([eq], [0], None, [256], [0, 256])

print(f"Original mean={img.mean():.2f}, Equalized mean={eq.mean():.2f}, Thresh white%={(thresh==255).mean()*100:.1f}%")
