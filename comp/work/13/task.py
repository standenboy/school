def get_name(name):
    return name.upper()


def get_age(current_age):
    return current_age + 1

def get_details(name,age):
    print(f"the persons name is {get_name(name)}, and next year they will be {get_age(age)}")

name = input("name: ")
age = int(input("current age: "))

get_details(name,age)
