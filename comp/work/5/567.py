import sys

for x in range(1,11):
	for i in range(x, (x*10)+1):
		if i % x == 0:
			if i >= 10:
				sys.stdout.write(str(i)+"   ")
			else:
				sys.stdout.write(str(i)+"   ")
	print("")  
