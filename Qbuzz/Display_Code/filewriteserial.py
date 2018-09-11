import serial
import os

#os.remove("testfile.txt");
os.system("sudo chmod a+rw /dev/ttyUSB0")
file=open("testfile.txt","w")
file.close()

while True:
        ser = serial.Serial('/dev/ttyUSB0')
        ser_bytes = ser.readline()
        print(ser_bytes)

	file = open("testfile.txt","a") 
	file.write(ser_bytes)
	file.close() 
