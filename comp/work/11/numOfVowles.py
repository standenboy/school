def count(string):
    counter = 0
    for i in string.lower():
        for j in ["a","e","i","o","u"]:
            if i == j:
                counter = counter + 1
    return counter
print(count("hello"))
