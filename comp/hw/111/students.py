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
    print('''
    90+ 2
    80+ 4
    70+ 2
    50+ 0
    <50 0
    ''')

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


print(calculate_mean("charlie"))
print(top_student())	
grade_spread()
print(improvement("alice"))
