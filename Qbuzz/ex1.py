import serial
import os

#os.remove("testfile.txt");

while True:
        ser = serial.Serial('/dev/ttyACM0')
        ser_bytes = ser.readline()
        print(ser_bytes)

	file = open("testfile.txt","w") 
	file.write(ser_bytes)
	file.close() 
