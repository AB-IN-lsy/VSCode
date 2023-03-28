'''
Author: NEFU AB-IN
Date: 2023-03-26 10:56:30
FilePath: \Acwing\241\241.py
LastEditTime: 2023-03-26 11:19:07
'''
# import
import sys, math
from collections import Counter, deque
from heapq import heappop, heappush
from bisect import bisect_left, bisect_right

# Final
N = int(2e5 + 10)
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


class Point:
    def __init__(self, ls, ll, rs, rl):
        self.ls = ls
        self.ll = ll
        self.rs = rs
        self.rl = rl


ans = [Point(0, 0, 0, 0) for _ in range(N)]

n, = read()
y = list(read())
y1 = y[::-1]

for i in range(n):
    # 左边比它小的
    ls = query(y[i] - 1)
    # 左边比它大的
    ll = i - query(y[i])
    add(y[i], 1)
    ans[i].ls = ls
    ans[i].ll = ll

tr = [0] * N
for i in range(n):
    # 右边比它小的
    rs = query(y1[i] - 1)
    # 右边比它大的
    rl = i - query(y1[i])
    add(y1[i], 1)
    ans[n - i - 1].rs = rs
    ans[n - i - 1].rl = rl

res1, res2 = 0, 0

for i in range(n):
    res1 += ans[i].ll * ans[i].rl
    res2 += ans[i].ls * ans[i].rs
print(res1, res2)