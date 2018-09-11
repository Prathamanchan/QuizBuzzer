#Never Give Up
import serial

while True:
        ser = serial.Serial('/dev/ttyACM0')
        ser_bytes = ser.readline()
        print(ser_bytes)

