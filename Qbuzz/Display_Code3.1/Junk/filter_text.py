#//Method-(1) Return you a proper int value(s)
a = 'RED 220 MS'
b = 'YELLOW 230 MS'
c = 'GREEN 440 MS'
d = 'ORANGE 330 MS'

for i in a,b,c,d:
	print(i)

Int = [int(i) for i in a.split() if i.isdigit()]
Vat = [i for i in a.split() if i.isalpha()]
print(Int) 
print(Vat[0]) 
team=Vat[0]

if  Vat[0]=='RED':
	time=Int
	print(Int)
