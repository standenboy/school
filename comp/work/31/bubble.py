import sys


def sort(list):
    length = len(list)
    for i in range(length - 1):
        for j in range(length - i - 1):
            if list[j] > list[j+1]:
                tmp = list[j]
                list[j] = list[j+1]
                list[j+1] = tmp
    return list


if __name__ == "__main__":
    count = int(sys.argv[1])

    num = []
    for i in range(count):
        num.append(int(input(f"number {i}: ")))

    print(sort(num))