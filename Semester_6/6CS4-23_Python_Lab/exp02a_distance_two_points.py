# Exp 2(a): Euclidean Distance Between Two Points
import math
x1, y1, x2, y2 = 1.0, 2.0, 4.0, 6.0
dist = math.hypot(x2 - x1, y2 - y1)
print(f"Distance between ({x1},{y1}) and ({x2},{y2}) = {dist:.2f}")
