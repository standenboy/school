results = []

more = "yes"

while more.lower() == "yes":
    result = 0
    tmp = []
    while True:
        result = int(input("result: "))
        if result == -1:
            break
        if result < 0:
            print("invalid input")
        elif result > 100:
            print("invalid input")
        else:
            tmp.append(result)
    results.append(tmp)
    more = input("add results for another student? ")

for i in range(len(results)):
    print("student",i+1,"got: ", *results[i])
