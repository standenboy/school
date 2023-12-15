def wage(hours, rate):
    pay = 0
    for i in range(hours):
        if i < 35:
            pay = pay + rate
        else:
            pay = pay + (rate + (rate * 0.5))
    return pay

print(wage(40, 10))
