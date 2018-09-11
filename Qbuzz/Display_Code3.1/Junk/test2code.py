#//Method-(1) Return you a proper int value(s)

f=open('junkfile.txt','r')
linelist=f.readlines()
count=-1
Int=[]
Garbage=[]
Vat=[]


for e in linelist:
	Int.append(1)
	Garbage.append(1)
	Vat.append(1)
	count=count+1

	Garbage[count] =map(int, [int(i) for i in e.split() if i.isdigit()])
	if len(Garbage[count]) != 0:
                Int[count]=Garbage[count].pop()
	Vat[count] = [i for i in e.split() if i.isalpha() and i!='MS']
 
	team=Vat[count]

if any("RED" in s for s in Vat):
	index=Vat.index(['RED'])
	red=Int[index]
	print(red)


if any("YELLOW" in s for s in Vat):
        index=Vat.index(['YELLOW'])
        yellow=Int[index]
        print(yellow)

if any("GREEN" in s for s in Vat):
        index=Vat.index(['GREEN'])
        green=Int[index]
        print(green)

if any("ORANGE" in s for s in Vat):
        index=Vat.index(['ORANGE'])
        orange=Int[index]
        print(orange)
