names = ["jacob", "thor", "katelyn", "johnson"]

searchingFor = input("name to look for: ")
for i in names:
    if i == searchingFor:
        print("found name")
        exit(0)

print("name not found")



