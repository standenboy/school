count = int(input("how many numbers will you input: "))
nums = []
for i in range(count):
    nums.append(int(input(f"num {i}: ")))

seen = []
seenicount = []
for i in range(len(nums)):
    seenicount.append(0)
    if nums[i] not in seen:
        for j in nums:
            if j == nums[i]:
                seenicount[i] += 1
        seen.append(nums[i])

highest = 0
multimodal = False
for i in seenicount:
    if i > highest:
        highest = i
    elif i == highest:
        multimodal = True

if (multimodal):
    print("data was multimodal")
else:
    print(highest)
