marks = []
marks.append(int(input("analysis: ")))
marks.append(int(input("design: ")))
marks.append(int(input("implimentation: ")))
marks.append(int(input("evaluation: ")))

total = 0
for i in marks:
    total = total + i

if total >= 80:
    print("9")
elif 80 > total >= 67:
    print("8")
elif 67 < total <= 54:
    print("7")
elif 54 < total <= 41:
    print("6")
elif 41 < total <= 31:
    print("5")
elif 31 < total <= 22:
    print("4")
elif 22 < total <= 13:
    print("3")
elif 13 < total <= 4:
    print("2")
elif 4 < total <= 2:
    print("1")
else:
    print("U")
print("total ", total)
