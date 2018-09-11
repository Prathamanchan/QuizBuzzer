from Tkinter import *

my_window=Tk()

label_1=Label(my_window,width="20",height="3",bg="red")
label_2=Label(my_window,width="20",height="3",bg="green")
label_3=Label(my_window,width="20",height="3",bg="blue")

label_1.grid(row=0,column=0)
label_2.grid(row=0,column=1)
label_3.grid(row=0,column=2)

my_window.mainloop()
