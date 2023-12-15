import string
def isLetter(letter):
    for i in list(string.ascii_lowercase):
        if letter == i:
            return True
    return False
print(isLetter('1'))
