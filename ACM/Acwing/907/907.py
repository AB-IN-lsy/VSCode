'''
Author: NEFU AB-IN
Date: 2022-03-15 11:29:16
FilePath: \ACM\Acwing\907.py
LastEditTime: 2022-03-15 14:06:24
'''
st, ed = map(int, input().split())

n = int(input())
a = []
for i in range(n):
    l, r = map(int, input().split())
    a.append([l, r])

a.sort()
res = 0

for i in range(n):
    j = i
    r = -int(2e9)
    while j < n and a[j][0] <= st:
        r = max(r, a[j][1])
        j += 1
    if r < st:
        res = -1
        break
    res += 1
    if r >= ed:
        break
    i = j - 1
    st = r

print(res)
