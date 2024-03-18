number = 0
while number < 1 or number > 10:
    number = input("enter a postive number: ")
    if number > 10:
        print("number is too big")
    else:
        if number < 1:
            print("not posative")
c = 1
for k in range(number-1):
    print(c)
    c = (c * number - 1 - k) / (k + 1)
