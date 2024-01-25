for i in range(1,12):
    for j in range(1,12):
        num = i * j
        if num < 10:
            print(f"00{num} ", end="")
        elif num < 100:
            print(f"0{num} ", end="")
        else:
            print(f"{num} ", end="")
    print()
