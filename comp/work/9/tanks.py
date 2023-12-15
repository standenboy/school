board1 = [["."]  * 10] * 10
board2 = [["."]  * 10] * 10

for i in board1:  
    print(*i, sep=" ")
for i in range(3):
    board1[int(input("tank y: "))][int(input("tank x: "))] = "T" 
for i in board1:  
    print(*i, sep=" ")

