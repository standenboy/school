toWrite = """Sword,5 
Mace,3 
Warhammer,8 
Shield,1 
Spear,6
"""

def getLowest(list):
    lowest = 1000 
    for i in list:
        if i < lowest:
            lowest = i
    return lowest

f = open("./items", "w")

f.write(toWrite)

f.close()

f = open("./items", "r")

items = []
for i in f.readlines():
    tmp = []
    tmp.append(i.split(",")[0])
    tmp.append(int(i.split(",")[1].strip("\n ")))
    items.append(tmp)

amounts = []
for i in items:
    amounts.append(i[1])
sorted = []

for x in range(len(items)):
    for i in items:
        if i[1] == getLowest(amounts):
            sorted.append(i[0])
            items.remove(i)
            amounts.remove(getLowest(amounts))

print(*sorted, sep=" ")
