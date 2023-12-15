name = ["tux", "wibler", "rms"]
clue1 = ["its a penguin", "it likes art", "what your refering to..."]
clue2 = ["it could have been a furry", "its a dog", "...as linux, is accutally gnu/linux"]

score = 0

for x in range(3):
    print(clue1[x])
    guess = input("who do you think it is? ")
    if guess == name[x]:
        print("you got it!")
        score = score + 5
    else:
        print(clue2[x])
        guess = input("who do you think it is now? ")
        if guess == name[x]:
            print("well done, you got it that time!")
            score = score + 2
        else:
            print("sorry that was wrong")
            print("it was,", name[x])
    print("\n\n\n")

print("you got,", score, "points")


