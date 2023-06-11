'''
Author: NEFU AB-IN
Date: 2023-06-09 21:52:11
FilePath: \LanQiao\2941\2941.py
LastEditTime: 2023-06-09 23:06:04
'''
# import
from sys import setrecursionlimit, stdin, stdout, exit
from collections import Counter, deque
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from bisect import bisect_left, bisect_right
from datetime import datetime, timedelta
from string import ascii_lowercase, ascii_uppercase
from math import log, gcd, sqrt, fabs, ceil, floor


class sa:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __lt__(self, a):
        return self.x < a.x


# Final
N = int(5e5 + 10)
M = 20
INF = int(2e9)

# Define
setrecursionlimit(INF)
input = lambda: stdin.readline().rstrip("\r\n")  # Remove when Mutiple data
read = lambda: map(int, input().split())
LTN = lambda x: ord(x.upper()) - 65  # A -> 0
NTL = lambda x: ascii_uppercase[x]  # 0 -> A

# —————————————————————Division line ——————————————————————

tr = [0] * N


def lowbit(x):
    return x & -x


def add(i, v):
    while i < N:
        tr[i] = max(tr[i], v)
        i += lowbit(i)


def query(i):
    ans = 0
    while i > 0:
        ans = max(tr[i], ans)
        i -= lowbit(i)
    return ans


a, dp = [0] * N, [0] * N
n, k = read()
a[1:] = read()
ans = 0

for i in range(1, n + 1):
    if i - k > 1:
        dp[i] = query(i - k - 1) + a[i]
    else:
        dp[i] = a[i]
    ans = max(ans, dp[i])
    add(i, dp[i])

print(ans)
