import serial
import os

#os.remove("testfile.txt");
file=open("testfile.txt","w")
file.close()

while True:
        ser = serial.Serial('/dev/ttyUSB0')
        ser_bytes = ser.readline()
        print(ser_bytes)

	file = open("testfile.txt","a") 
	file.write(ser_bytes)
	file.close() 
