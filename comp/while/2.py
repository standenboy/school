import random

guess = -1
ans = random.randint(1,100)

while guess != ans:
    guess = int(input("guess: "))
    if guess < ans:
        print("higher")
    elif guess > ans: 
        print("lower")


