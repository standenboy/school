sentence = input("sentence: ")

cons = 0
spaces = 0

for i in sentence:
        if i == ' ':
                spaces =+ 1

        if i != 'a' and i != 'e' and i != 'i' and i != 'o' and i != 'u':
                cons = cons + 1
print("there are", cons - 2, "consinants and", spaces + 2, "words")
