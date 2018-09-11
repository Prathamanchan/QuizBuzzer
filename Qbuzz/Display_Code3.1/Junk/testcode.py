#//Method-(1) Return you a proper int value(s)

a = 'RED 100 MS'
d = 'YELLOW 230 MS'
b = 'GREEN 440 MS'
c = 'ORANGE 330 MS'
count=-1
Int=[0]
Garbage=[0]
Vat=['a']

for e in a,b,c,d:
	Int.append(1)
	Garbage.append(1)
	Vat.append(1)
	print(e)
	count=count+1

	Garbage[count] =map(int, [int(i) for i in e.split() if i.isdigit()])
	if len(Garbage[count]) != 0:
		Int[count]=Garbage[count].pop()
	Vat[count] = [i for i in e.split() if i.isalpha() and i!='MS']
	print(Int[count]) 
	print(Vat[count]) 
	team=Vat[count]

if any("RED" in s for s in Vat):
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
