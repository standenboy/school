import sys
num = []
num.append(int(input("number: ")))
num.append(int(input("number: ")))
num.append(int(input("number: ")))

num.sort()
for i in num:
    sys.stdout.write(f"{i} ")
print("\n")
