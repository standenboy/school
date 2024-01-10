import sys

num1 = int(input("num 1: "))
num2 = int(input("num 2: "))

for i in range(num1, num2+1):
    sys.stdout.write(f" {str(i)}")
print()
