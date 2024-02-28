import random
serverPortNames = [["http", 80], ["ftp control", 21], ["ftp data", 20], ["https", 443], ["pop3", 110], ["smtp", 25], ["ssh (the best one)", 22]]

while len(serverPortNames) != 0:
    randNum = random.randint(0, len(serverPortNames) - 1)
    ans = int(input(f"what is the port number of {serverPortNames[randNum][0]}: "))
    if ans == serverPortNames[randNum][1]:
        print("you did it!")
        serverPortNames.pop(randNum)
    else:
        print("you got it wrong, sorry")
