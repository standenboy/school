num = 0
highest = 0
lowest = 0
while num != -1:
    num = int(input("num: "))
    if num > highest:
        highest = num
    if num < lowest:
        lowest = num
print("the highest value was",highest,"and the lowest value was",lowest)
