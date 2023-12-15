numbers = []
for i in range(10):
    numbers.append(int(input("number: ")))
total = sum(numbers)
mean = total / len(numbers)

print("total =",total, "mean =",mean)

above = 0
for i in numbers:
    if i < mean:
        print(i, "is less than average (HA SMOL)")
    elif i == mean:
        print(i, "is average (BORINGGG)")
    else:
        print(i, "is more than average (DAMMNNNN)")
        above = above + 1
print(above, "numbers are above average")
