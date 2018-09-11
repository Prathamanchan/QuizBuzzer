#Never give Up


from Tkinter import *
import serial
import os

os.system("sudo chmod a+rw /dev/ttyUSB0")
os.system("python filewriteserial.py &")
root=Tk()
root.title("Quiz Buzzer")

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
start.pack(fill=BOTH,expand=1)
#start.grid(row=0,column=0,rowspan=2,columnspan=3)

stop=Button(bottomframe,text="Stop",command=clear)
stop.pack(fill=BOTH,expand=1)
#stop.grid(row=0,column=6,rowspan=2,columnspan=3)

w=Label(frame,image=logo)
w.pack()
root.geometry("300x300")
root.mainloop()

