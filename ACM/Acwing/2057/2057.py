'''
Author: NEFU AB-IN
Date: 2022-05-19 17:45:22
FilePath: \ACM\Acwing\2057.py
LastEditTime: 2022-05-19 17:53:58
'''
d, h, m = map(int, input().split())

if d == 11 and (h < 11 or (h == 11 and m < 11)):
    print(-1)
    exit(0)

if d > 11:
    ht, mt = 24, 0
    d -= 1
    ht += h
    mt += m
    if d > 11:
        ht += (24 * (d - 11))
else:
    ht, mt = h, m

st = 11 * 60 + 11
et = ht * 60 + mt

print(et - st)
