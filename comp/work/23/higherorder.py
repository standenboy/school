def shout(word):
    return (word.upper())

def wisper(word):
    return (word.lower())

def say(func):
    print(func("heLLo"))

say(shout)
