nums = [[3,7,12,5],[8,4,1,6],[15,0,2,6]]

def mysum(list):
    total = 0
    for i in list:
        total = total + i
    return total


total = 0
for i in nums:
    total = total + mysum(i)

print(total)
