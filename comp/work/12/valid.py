def validName(name):
    valid = True
    for letter in name:
        if letter.upper() > "Z" or letter.upper() < "A":
            if letter != "-" and letter != " ":
                valid = False
    return valid

def validNumber(number):
    try:
        int(number)
    except:
        return False
    return True

def validYear(year):
    year = int(year)
    if year < 1900:
        return False
    if year > 2099:
        return False
    return True

def validMonth(month):
    month = int(month)
    if month <= 0:
        return False
    if month > 12:
        return False
    return True

def rangeCheck(number, lower, upper):
    if number > upper or number < lower:
        return False
    return True

def dateCheck(date):
    if len(date) != 10:
        return False
    if not(validNumber(date[0]) and validNumber(date[1]):
        return False
    if not(validNumber(date[3]) and validNumber(date[4]):
        return False
    if not(validNumber(date[6]) and validNumber(date[7]) and validNumber(date[8]) and validNumber(date[9]):
        return False
    return True

if __name__ == "__main__":
    firstName = input("Please type in your firstname: ")
    number = input("please type a phone number: ")
    year = input("what is the year: ")

    while not(validName(firstName)):
        firstName = input("Please type in your firstname: ") 

    while not(validNumber(number)):
        number = input("Please type in a valid phone number: ") 

    while not(validYear(year)):
        year = input("Please type in a valid year: ") 
