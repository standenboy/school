import random, sys

def randomchar():
    num = random.randint(65, 90)
    return chr(num)

def fliprandom(char):
    if random.randint(0,1) == 0:
        return char.lower()
    else:
        return char

def usenumber(char):
    if random.randint(0,3) == 0:
        return ord(char)
    else:
        return char

def shift(char):
    if random.randint(0,1) == 0:
        return chr(random.randint(58, 63))
    else:
        return char
    
password = []

for i in range(30):
    password.append(usenumber(fliprandom(shift(randomchar()))))

for i in password:
    sys.stdout.write(str(i))

print("")
