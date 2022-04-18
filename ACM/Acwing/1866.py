'''
Author: NEFU AB-IN
Date: 2022-04-08 15:47:47
FilePath: \ACM\Acwing\1866.py
LastEditTime: 2022-04-08 15:47:47
'''
INF = int(1e9)
L, R = -INF, -INF

a = []
for i in range(2):
    l, r = map(int, input().split())
    a.append([l, r])
a.sort()

res = 0
for l, r in a:
    if R < l:
        if L != -INF and R != -INF:
            res += (R - L)
        L, R = l, r
    else:
        R = max(R, r)

if L != -INF and R != -INF:
    res += (R - L)

print(res)