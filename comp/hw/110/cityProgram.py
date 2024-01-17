Country = ["France", "UK", "Italy", "Spain"]
Capital = ["Paris", "London", "Rome", "Madrid"]

def add(country, capital):
    Country.append(country)    
    Capital.append(capital)

def remove(country):
    counter = 0
    for i in Country:
        if i == country:
            Country.pop(counter)
            Capital.pop(counter)
            break
        counter = counter+1        

def printCountry():
    counter = 0
    for i in Country:
        print(Country[counter], Capital[counter] )
        counter = counter + 1 

while True:
    query = input("add, remove, print: ")
    if query == "add":
        add(input("country: "), input("capital: "))
        printCountry()
    elif query == "remove":
        remove(input("country to remove: "))
        printCountry()
    elif query == "print":
        printCountry()





