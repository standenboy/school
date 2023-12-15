string = "HELLO_THERE"
shift = 4 
hidden = []
tmp = ""
for i in string:
    if len(tmp) + 1 > shift:
        hidden.append(tmp)
        tmp = ""
    tmp = tmp + i
if len(tmp) != 0:
    hidden.append(tmp)
final = []
for i in range(shift):
    for j in hidden:
        try:
            final.append(j[i])
        except:
            pass
print(final)
