names = []
for i in range(5):
    name = input("name: ")
    names.append(name)

f = open("names.txt", "r+")
for i in names:
    i = i+"\n"
    f.write(i)

nameToSearch = input("name to search: ")
for i in f.readlines():
    if i.split("\n")[0] == nameToSearch:
        print("name found")
        break
