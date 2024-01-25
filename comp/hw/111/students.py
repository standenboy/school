students = [['alice', [75,80,85,90]], ['bob',[60,65,70,75]],['charlie',[90,85,80,78]]]


def calculate_mean(name):
    for i in students:
        if i[0] == name:
            mean = sum(i[1]) / len(i[1])
            return mean
    return "not in list"

def top_student():
    top = 0
    for i in students:
        this_student_mean = calculate_mean(i[0])
        if this_student_mean > top:
            top = this_student_mean
    for i in students:
        if calculate_mean(i[0]) == top:
            return i[0]

def grade_spread():
    prev = 0
    current = 50
    count = 0
    for x in range(6): 
        for i in students:
            for j in i[1]:
                if j <= current:
                    count = count + 1
        print(f"{prev} - {current}: {count}")
        prev = current
        current = current + 10

def improvement(name):
    for i in students:
        if i[0] == name:
            low = i[1][0]
            high = 0
            for i in i[1]:
                if i < low:
                    low = i
                elif i > high:
                    high = i
            range = high - low
            return range
    return "not in list"


print(f"mean for charle: {calculate_mean('charlie')}")
print(f"the top student is: {top_student()}")	
print("the grade spread is")
grade_spread()
print(f"the grade improvement of alice is: {improvement('alice')}")
