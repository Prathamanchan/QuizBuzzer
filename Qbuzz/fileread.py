# Open a file
fo = open("testfile.txt", "r+")
str = fo.read();
print "Read String is : ", str

fo.close()
