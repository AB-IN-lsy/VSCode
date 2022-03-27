'''
Author: NEFU AB-IN
Date: 2022-03-26 16:29:22
FilePath: \ACM\Acwing\1265.py
LastEditTime: 2022-03-26 16:34:12
'''
from collections import Counter

N = int(2e4 + 10)
tr, a = [0] * N, []


def lowbit(x):
    return x & -x


def add(x, d):
    while x < N:
        tr[x] += d
        x += lowbit(x)


def query(x):
    res = 0
    while x:
        res += tr[x]
        x -= lowbit(x)
    return res


n = int(input())
for i in range(n):
    x, y = map(int, input().split())
    x += 1
    y += 1
    a.append([x, y])

a.sort()
a = [0, *a]

d = Counter()
for i in range(1, n + 1):
    d[query(a[i][1])] += 1
    add(a[i][1], 1)

for i in range(n):
    print(d[i])