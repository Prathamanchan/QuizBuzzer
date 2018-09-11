from Tkinter import *
 
class yadayadayada():
 
    def __init__(self, root):
 
        #create a List with a tuple for:
            #1) every button that needs to be created and
            #2) what function it executes
        listOfFunctions = [("hi",self.hi),("bye",self.bye),("what",self.what)]
 
        #TK stuff
        frame = Frame(root)
        frame.pack()
 
        #iterate thru List and create buttons dynamically
        i = 0
        for stuff in listOfFunctions:
            
            buttonText = listOfFunctions[i][0] #first value in tuple
            buttonAction = listOfFunctions[i][1] #second value in tuple
 
            #make the button and assign the command to execute
            self.makeButton = Button(frame, text=buttonText, command=buttonAction) 
            self.makeButton.pack()
            
            i = i + 1
 
    #just some placeholder functions
    def hi(self):
        print ("hi")
 
    def bye(self):
        print ("bye")
 
    def what(self):
        print ("what now?")
 
#make it go
root = Tk()
yadayadayada = yadayadayada(root)
root.mainloop()
