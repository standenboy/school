def split(list):
    length = len(list)
    l1 = []
    l2 = []
    for i in range(length):
        if i >= (length / 2):
            l2.append(list[i])
        else:
            l1.append(list[i])
    if length > 2:
        l1 = split(l1)
        l2 = split(l2)
    return merge(l1, l2)


def merge(l1, l2):
    i = 0
    j = 0
    output = []
    while i < len(l1) and j < len(l2):
        if l1[i] < l2[j]:
            output.append(l1[i])
            i += 1
        else:
            output.append(l2[j])
            j += 1

    while i < len(l1):
        output.append(l1[i])
        i += 1
    while j < len(l2):
        output.append(l2[j])
        j += 1
    return output


# call split on the list, will return  a sorted one
print(split([1, 4, 2, 4, 2, 5, 6, 2, 7]))
