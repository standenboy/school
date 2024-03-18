def addative(num):
    if len(num) >= 2:
        new = 0
        for i in num:
            new = new + int(i)
        return 1 + addative(str(new))
    else:
        return 0


def multiplative(num):
    if len(num) >= 2:
        new = 1 
        for i in num:
            new = new * int(i)
        return 1 + addative(str(new))
    else:
        return 0


num = input("number: ")

if input("m/a: ") == "m":
    print(multiplative(str(num)))
else:
    print(addative(str(num)))
