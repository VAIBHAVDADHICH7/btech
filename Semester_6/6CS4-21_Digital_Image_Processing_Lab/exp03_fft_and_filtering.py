# Exp 3: 2D Fourier Transform, Linear Convolution & Non-Linear Median Filtering
import numpy as np
import cv2

img = np.zeros((128, 128), dtype=np.uint8)
cv2.circle(img, (64, 64), 30, 255, -1)

fft_shift = np.fft.fftshift(np.fft.fft2(img))
magnitude_spectrum = 20 * np.log(np.abs(fft_shift) + 1)

kernel = np.ones((5, 5), np.float32) / 25.0
linear_filtered = cv2.filter2D(img, -1, kernel)
nonlinear_median = cv2.medianBlur(img, 5)

print("FFT max mag:", round(float(magnitude_spectrum.max()), 2),
      "| Linear mean:", round(float(linear_filtered.mean()), 2),
      "| Median mean:", round(float(nonlinear_median.mean()), 2))
