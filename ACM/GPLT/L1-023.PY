from collections import Counter

s = input()
s = s.upper()
d = Counter(s)

t = "GPLT"
while True:
    cnt = 0
    for i in t:
        if d[i]:
            d[i] -= 1
            print(i, end="")
        else:
            cnt += 1
    if cnt == 4:
        break
