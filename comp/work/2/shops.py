total = int(input("how much does it cost: "))
totalPayed = int(input("how much did you get: "))

if totalPayed < total:
	print(f"{totalPayed:.2f} is not enough to pay for {total:.2f}")
	exit()

totalChange = totalPayed - total
changeToGive = []
while totalChange != 0:
	if totalChange >= 10:
		totalChange = totalChange - 10
		changeToGive.append(10)
	elif totalChange >= 5:
		totalChange = totalChange - 5
		changeToGive.append(5)
	elif totalChange >= 2:
		totalChange = totalChange - 2
		changeToGive.append(2)
	elif totalChange >= 1:
		totalChange = totalChange - 1
		changeToGive.append(1)

print(f"you need to give the customer : {changeToGive}")

