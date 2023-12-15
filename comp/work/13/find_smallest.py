def find_smallest(numbers):
	smallest = numbers[0]
	for i in numbers:
		if i < smallest:
			smallest = i
	return smallest

numbers = [3, 6, 2, 8, 4, 1]
print(find_smallest(numbers))
