# Exp 2: Python Basics on Raspberry Pi
import math

name = "RaspberryPi User"
print(f"Hello, {name}!")

a, b = 15, 4
print(f"Sum={a+b}, Diff={a-b}, Prod={a*b}, Div={a/b:.2f}")

sentence = "Internet of Things with Raspberry Pi"
print(f"Words={len(sentence.split())}, Chars={len(sentence)}")

print(f"Area(Rect 5x3)={5*3}, Area(Tri 4x6)={0.5*4*6}, Area(Circle r=3)={math.pi*9:.2f}")
