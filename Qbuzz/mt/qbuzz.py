#Never give Up


from Tkinter import *
import serial
import os

root=Tk()
root.title("Quiz Buzzer")

try:
	thread.start_new_thread(serialRead)
except:
	print "Error: Unable to start thread"

def readFile():
	fo=open("testfile.txt","r+")
	str=fo.read();
	msg.config(text=str)
	fo.close()

def clear():
	msg.config(text=" ")

logo=PhotoImage(file="qbuzz.png")

frame=Frame(root,bg="white")
frame.pack()

midframe=Frame(root,bg="white")
midframe.pack(fill=BOTH,expand=1)

bottomframe=Frame(root,bg="blue")
bottomframe.pack(side=BOTTOM,fill=BOTH,expand=1)

message="Never Mind"
msg=Message(midframe,text=message)
msg.config(bg="white",font=('times',11,'italic'))
msg.pack()

start=Button(bottomframe,text="Start",command=readFile)
start.grid(row=0,column=0,rowspan=2,columnspan=3)

stop=Button(bottomframe,text="Stop",command=clear)
stop.grid(row=0,column=3,rowspan=2,columnspan=3)

w=Label(frame,image=logo)
w.pack()
root.geometry("500x300")
root.mainloop()

def serialRead():

	while True:
		ser = serial.Serial('/dev/ttyACM0')
	        ser_bytes = ser.readline()
       		print(ser_bytes)

       		file = open("testfile.txt","w") 
       		file.write(ser_bytes)
       		file.close() 

