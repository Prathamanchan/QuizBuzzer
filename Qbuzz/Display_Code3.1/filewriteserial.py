import serial
import os
import tkMessageBox

os.system("sudo chmod a+rw /dev/ttyACM0")
os.system("touch testfile.txt")
file=open("testfile.txt","w")
file.close()

while True:

        ser = serial.Serial('/dev/ttyACM0')
        ser_bytes = ser.readline()
        print(ser_bytes)

	file = open("testfile.txt","a") 
	file.write(ser_bytes)
	file.close() 


	#print("Error Could not read from port")
		
