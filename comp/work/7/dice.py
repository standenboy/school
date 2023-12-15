import random

dice = []
for i in range(200):
    dice.append(random.randint(1, 6))

count = []
for i in range(6):
    count.append(0)
for i in dice:
    if i == 1:
        count[0] = count[0] + 1
    elif i == 2:
        count[1] = count[1] + 1
    elif i == 3:
        count[2] = count[2] + 1
    elif i == 4:
        count[3] = count[3] + 1
    elif i == 5:
        count[4] = count[4] + 1
    else:
        count[5] = count[5] + 1

for i in range(len(count)):
    print("there are", count[i], str(i)+"'s")

