import sys
for i in range(1,11):
    for j in range(1,11):
        num = i*j
        if i == j:
            sys.stdout.write("* ")
        elif i + j == 11:
            sys.stdout.write("$ ")
        else:    
            sys.stdout.write(f"{str(j*i)} ")
    print()
