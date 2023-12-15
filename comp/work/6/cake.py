while True:
    eggs = int(input("how many eggs are there: "))
    if eggs < 8:
        break
flour = eggs * 100
sugar = eggs * 50

print("you will need", flour, "grams and", sugar, "grams") 
