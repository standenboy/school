num = int(input("number: "))

if num < 0:
    exit(1)

for i in range(num+1):
    if (i % 5) == 0:
        print(i)
