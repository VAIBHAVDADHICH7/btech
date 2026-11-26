# Exp 6: Sensor Interfacing (Ultrasonic Distance, UART Temp/Humidity, I2C LCD)
def ultrasonic_distance_cm(pulse_duration_sec: float) -> float:
    # Speed of sound = 34300 cm/s (round-trip / 2)
    return round((pulse_duration_sec * 34300.0) / 2.0, 2)

print("Sample Ultrasonic Distance (pulse=1.2ms):", ultrasonic_distance_cm(0.0012), "cm")
print("UART Temp/Humidity & I2C LCD: connect via pyserial (/dev/serial0) and smbus2 (addr 0x27) on Raspberry Pi.")
