'''
Author: NEFU AB-IN
Date: 2023-03-26 10:14:42
FilePath: \Acwing\3662\3662.py
LastEditTime: 2023-03-26 10:37:34
'''
# import
import sys
from collections import Counter, deque
from heapq import heappop, heappush
from bisect import bisect_left, bisect_right

# Final
N = int(1e5 + 10)
INF = int(2e9)

# Define
sys.setrecursionlimit(INF)
read = lambda: map(int, input().split())

tr = [0] * N


def lowbit(x):
    return x & -x


def add(x, v):
    while x < N:
        tr[x] = max(tr[x], v)
        x += lowbit(x)


def query(x):
    res = 0
    while x:
        res = max(res, tr[x])
        x -= lowbit(x)
    return res


n, = read()
a = list(read())

xs = a[:]
xs = sorted(list(set(xs)))

res = 0
for i in range(n):
    k = bisect_left(xs, a[i]) + 1  # 保证下标大于0
    s = query(k - 1) + a[i]
    res = max(res, s)
    add(k, s)

print(res)