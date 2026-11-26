# Exp 4: Raspberry Pi GPIO — LED Blink, Push-Button Toggle & File-Driven Intervals
import time
try:
    import RPi.GPIO as GPIO
except ImportError:
    class MockGPIO:
        BCM = OUT = IN = PUD_UP = HIGH = LOW = 1
        def setmode(self, *a): pass
        def setup(self, *a, **k): pass
        def output(self, pin, val): print(f"[MockGPIO] Pin {pin} -> {'ON' if val else 'OFF'}")
        def input(self, pin): return 0
        def cleanup(self): pass
    GPIO = MockGPIO()

LED_PIN, BTN_PIN = 17, 27
GPIO.setmode(GPIO.BCM)
GPIO.setup(LED_PIN, GPIO.OUT)
GPIO.setup(BTN_PIN, GPIO.IN, pull_up_down=GPIO.PUD_UP)

intervals = [(0.2, 0.2), (0.5, 0.2)]
for on_t, off_t in intervals:
    GPIO.output(LED_PIN, GPIO.HIGH); time.sleep(on_t)
    GPIO.output(LED_PIN, GPIO.LOW);  time.sleep(off_t)
GPIO.cleanup()
