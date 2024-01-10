import random

words = ["hello", "there", "this", "is", "a", "line"]

for i in range(6):
    word = words[random.randint(0,len(words)-1)]
    print(word)
    words.remove(word)
