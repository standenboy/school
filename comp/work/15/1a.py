def addTo(file):
    f = open(file, "w")
    towrite = [] 
    line = ""
    while line != "quit\n":
        line = input()
        line = line + "\n"
        towrite.append(line)
    towrite.remove("quit\n")
    f.writelines(towrite)
    f.close()

def readFile(file):
    f = open(file, "r")
    print(*f.readlines(), sep="")
    f.close()

def readFileReverse(file):
    f = open(file, "r")
    towrite = ""
    for i in f.readlines():
        towrite = towrite + i 
    print(towrite[::-1])
    f.close()



file = "./file"
addTo(file)
readFileReverse(file)
