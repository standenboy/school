import merge
import bubble


while True:
    list = []
    inp = ""
    print("enter nums, then enter END")
    while inp != "END":
        inp = input("number: ")
        if inp != "END":
            list.append(inp)

    sort = int(input("1) bubble, 2) merge: "))

    if sort == 1:
        print(*merge.sort(list), sep=", ")

    else:
        print(*bubble.sort(list), sep=", ")
