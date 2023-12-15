while True:
    week = input("is it a week day: (yes/no) ").lower()
    if week == "yes":
        break
    elif week == "no":
        break
    
while True:
    temp = int(input("what is the temprature: "))
    if temp >= 20:
        if temp <= 45:
            break
sold = 0
if week == "no":
    if 20 <= temp <= 30:
        sold = 200
    elif 31 <= temp <= 38:
        sold = 300
    else:
        sold = 240
elif week == "yes":
    if 20 <= temp <= 30:
        sold = 200/2
    elif 31 <= temp <= 38:
        sold = 300/2
    else:
        sold = 240/2
print(sold, "ice creams will be sold")

