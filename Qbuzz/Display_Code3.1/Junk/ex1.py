f=open('junkfile.txt','r')

linelist=f.readlines()
count=len(linelist)
y=linelist.pop(0)
print y
print(count)

#for x in linelist:
#	print x
