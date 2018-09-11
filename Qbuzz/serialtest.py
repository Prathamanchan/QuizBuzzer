import serial

while True:
	ser = serial.Serial('/dev/ttyUSB0')
	ser_bytes = ser.readline()
	print(ser_bytes)
	
	
