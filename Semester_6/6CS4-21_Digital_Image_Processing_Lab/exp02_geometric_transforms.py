# Exp 2: Image Rotation, Scaling, and Translation
import numpy as np
import cv2

img = np.zeros((200, 200), dtype=np.uint8)
cv2.rectangle(img, (60, 60), (140, 140), 255, -1)

h, w = img.shape
M_trans = np.float32([[1, 0, 25], [0, 1, 15]])
translated = cv2.warpAffine(img, M_trans, (w, h))

M_rot = cv2.getRotationMatrix2D((w / 2, h / 2), 45, 1.0)
rotated = cv2.warpAffine(img, M_rot, (w, h))

scaled = cv2.resize(img, None, fx=1.5, fy=1.5, interpolation=cv2.INTER_LINEAR)
print("Shapes -> Translated:", translated.shape, "Rotated:", rotated.shape, "Scaled:", scaled.shape)
