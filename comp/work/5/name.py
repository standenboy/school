name = input("name: ")
counter = len(name)
for i in name:
        print(f"{name:.{counter}}")
        counter = counter - 1
