scores = [[]]
for i in range(3):
    tmp = []
    for j in range(5):
        tmp.append(int(input(f"num {j}: ")))
    scores.append(tmp)

scores.pop(0)
for i in scores:
    print(*i, "avg: ",(sum(i)/5), sep=" ")

highest = scores[0][0]
lowest = scores[0][0]
for i in scores:
    for j in i:
        if j > highest:
            highest = j
        elif j < lowest:
            lowest = j
print(f"highest: {highest}, lowest: {lowest}")

