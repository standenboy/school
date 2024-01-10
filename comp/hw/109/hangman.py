import random
words = ["hello", "there", "this", "is", "a", "line"]

word = words[random.randint(0,len(words)-1)]

print(len(word))

for i in range(5):
    letter = input("guess a letter: ")
    if letter in word:
        print("yes")
    else:
        print("no")

guess = input("guess the word: ")
if guess == word:
    print("you win")
else:
    print("!(you win)")
