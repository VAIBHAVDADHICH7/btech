# Exp 5: Morphological Operations (Erosion, Dilation, Opening, Closing)
import numpy as np
import cv2

binary = np.zeros((64, 64), dtype=np.uint8)
cv2.rectangle(binary, (16, 16), (48, 48), 255, -1)
binary[5, 5] = 255   # small noise dot
binary[32, 32] = 0   # small hole

se = cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3))
eroded = cv2.erode(binary, se)
dilated = cv2.dilate(binary, se)
opened = cv2.morphologyEx(binary, cv2.MORPH_OPEN, se)
closed = cv2.morphologyEx(binary, cv2.MORPH_CLOSE, se)

print("Foreground pixels -> Original:", (binary > 0).sum(),
      "Eroded:", (eroded > 0).sum(), "Dilated:", (dilated > 0).sum(),
      "Opened:", (opened > 0).sum(), "Closed:", (closed > 0).sum())
