'''
Author: NEFU AB-IN
Date: 2023-03-26 11:48:05
FilePath: \Acwing\242\242.py
LastEditTime: 2023-03-26 11:55:10
'''
# import
import sys, math
from collections import Counter, deque
from heapq import heappop, heappush
from bisect import bisect_left, bisect_right

# Final
N = int(1e5 + 10)
INF = int(2e9)

# Define
sys.setrecursionlimit(INF)
read = lambda: map(int, input().split())

# —————————————————————Division line ————————————————————————————————————————
tr = [0] * N


def lowbit(x):
    return x & -x


def add(x, v):
    while x < N:
        tr[x] += v
        x += lowbit(x)


def query(x):
    res = 0
    while x:
        res += tr[x]
        x -= lowbit(x)
    return res


n, m = read()
a = [0] + list(read())
for i in range(1, n + 1):
    add(i, a[i] - a[i - 1])

for _ in range(m):
    op = list(input().split())
    if op[0] == 'C':
        l, r, d = map(int, op[1:])
        add(l, d)
        add(r + 1, -d)
    else:
        print(query(int(op[1])))
