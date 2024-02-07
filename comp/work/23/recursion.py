def factorial(num):
    if num == 0:
        return 0 
    else:
        return num + factorial(num - 1)

print(factorial(23))
