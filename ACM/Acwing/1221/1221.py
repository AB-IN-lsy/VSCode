'''
Author: NEFU AB-IN
Date: 2022-03-22 20:26:55
FilePath: \ACM\Acwing\1221.py
LastEditTime: 2022-03-22 21:17:54
'''
from math import sqrt
from collections import Counter

n = int(input())

N = int(sqrt(n))
d = Counter()

for i in range(N + 1):
    for j in range(i, N + 1):
        res = i * i + j * j
        if res <= n and (not d[res] or [i, j] < d[res]):
            d[res] = [i, j]

ans = []
st = Counter()

for i in d.keys():
    if d[n - i]:
        a, b = d[i]
        c, d = d[n - i]
        print(a, b, c, d)
        exit(0)
