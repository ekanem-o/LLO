import serial
import time

# Replace with your Arduino's port
arduino_port = '/dev/tty.usbserial-110'  # e.g., '/dev/ttyUSB0' on Linux/Mac
baud_rate = 9600

# Text to send to printer
message = """
Hello from Python!
This is a test message printed via Arduino and thermal printer.

Enjoy your prints! :)
"""

# Open serial connection
with serial.Serial(arduino_port, baud_rate, timeout=1) as ser:
    time.sleep(2)  # wait for Arduino to reset (important!)
    
    # Send each line with newline terminator
    for line in message.strip().split('\n'):
        ser.write(line.strip().encode('utf-8'))
        ser.write(b'\n')  # send newline
        time.sleep(0.1)   # small delay between lines

    # Optional: feed paper a bit
    ser.write(b'\n\n\n')
