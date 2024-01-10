matrix = [[1,2,3],[4,5,6],[7,8,9]]

num = int(input("number: "))

for i in matrix:
    for j in i:
        if j == num:
            print("true")
            exit(0) 
print("false")
