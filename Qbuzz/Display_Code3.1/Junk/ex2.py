#//Method-(1) Return you a proper int value(s)

a = 'RED 220 MS'
b = 'YELLOW 230 MS'
c = 'GREEN 440 MS'
d = 'ORANGE 330 MS'
count=-1
Int=[0,0,0,0,0]
Vat=['R','g','f','a','r']

for e in a,b,c,d:
	print(e)
	count=count+1
	print e.split()
	Int[count] = [i for i in e.split() if i.isdigit() and isinstance(int(i),int)]
	Vat[count] = [i for i in e.split() if i.isalpha() and i!='MS']
	print(Int[count]) 
	print(Vat[count]) 
	team=Vat[count]

if any("RED" in s for s in Vat):
	index=Vat.index(['RED'])
	red=Int[index]
	print(red)


if any("YELLOW" in s for s in Vat):
        index=Vat.index(['RED'])
        red=Int[index]
        print(red)

if any("GREEN" in s for s in Vat):
        index=Vat.index(['GREEN'])
        green=Int[index]
        print(green)

if any("ORANGE" in s for s in Vat):
        index=Vat.index(['ORANGE'])
        orange=Int[index]
        print(orange)

if any("YELLOW" in s for s in Vat):
        index=Vat.index(['YELLOW'])
        yellow=Int[index]
        print(yellow)
