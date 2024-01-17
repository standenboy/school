def validquantity(num):
    try:
        num = int(num)
    except Exception as e:
        print("invalid input: NOT INT") 
        return False
    if num < 0:
        print("invalid input: NUMBER LESS THAN 0")
        return False
    return True

def validprice(num):
    try:
        num = float(num)
    except Exception as e:
        print("invalid input: NOT INT") 
        return False
    if num < 0:
        print("invalid input: NUMBER LESS THAN 0")
        return False
    if (str(num)[::-1].find('.') > 2): 
        print("invalid input: NUMBES HAS TO MANY DECIMAL PLACES")
        return False
    return True
    

f = open("price.txt", "r")
for i in f.readlines():
    item = i.split(",")[0]
    quantity = i.split(",")[1]
    price = i.split(",")[2]
    
    if (validquantity(quantity) == False):
        exit(1)
    elif (validprice(price) == False):
        exit(1)
    quantity = int(quantity)
    price = float(price)
    print(f"{item} will cost {price*quantity:.02f}")    
