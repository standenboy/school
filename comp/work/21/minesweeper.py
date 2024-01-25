import random
grid = [
        [0,0,0,0,0,0],
        [0,0,0,0,0,0],
        [0,0,0,0,0,0],
        [0,0,0,0,0,0],
        [0,0,0,0,0,0],
        [0,0,0,0,0,0],
        ]

def getValidPos(text):
    inp = -1
    while inp < 1 or inp > 6:
        inp = int(input(text))
    return inp

def printGrid():
    for i in grid:
        for j in i:
            if j == "B":
                print("0", end = " ")
            else:
                print(j, end = " ")
        print()

def placeBombs(amount):
    for i in range(amount):
        grid[random.randint(0,5)][random.randint(0,5)] = "B" 

def isMineNear(row, collumn):
    row = row - 1
    collumn = collumn - 1
    try:
        if grid[row][collumn+1] == "B":
            print("a bomb is near")
        elif grid[row][collumn-1] == "B":
            print("a bomb is near")
        elif grid[row+1][collumn] == "B":
            print("a bomb is near")
        elif grid[row-1][collumn] == "B":
            print("a bomb is near")
        elif grid[row+1][collumn+1] == "B":
            print("a bomb is near")
        elif grid[row-1][collumn-1] == "B":
            print("a bomb is near")
        elif grid[row-1][collumn+1] == "B":
            print("a bomb is near")
        elif grid[row+1][collumn-1] == "B":
            print("a bomb is near")
    except:
        pass


placeBombs(10)

score = 0
while True:
    printGrid()
    row = getValidPos("row: ")
    collumn = getValidPos("collumn: ")
    if grid[row-1][collumn-1] == "B":
        print("you blew up, your score was", score)
        break 
    grid[row-1][collumn-1] = "G" 
    score = score + 1 
    isMineNear(row, collumn)
