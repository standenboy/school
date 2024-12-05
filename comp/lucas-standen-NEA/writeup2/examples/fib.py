def fib(n):
    if (n < 2):
        return n

    return fib(n-1) + fib(n-2)

val = 30
print(fib(val))
