vowels = ['a','e','i','o','u']

counter = 0
word = input()
for i in word:
    for j in vowels:
        if j == i:
            counter = counter + 1 
print(counter)
