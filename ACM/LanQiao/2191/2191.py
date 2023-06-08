'''
Author: NEFU AB-IN
Date: 2023-05-24 19:49:37
FilePath: \LanQiao\2191\2191.py
LastEditTime: 2023-05-24 20:04:54
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
N = int(2e5 + 10)
M = 20
INF = int(2e9)

# Define
setrecursionlimit(INF)
input = lambda: stdin.readline().rstrip("\r\n")  # Remove when Mutiple data
read = lambda: map(int, input().split())
LTN = lambda x: ord(x.upper()) - 65  # A -> 0
NTL = lambda x: ascii_uppercase[x]  # 0 -> A

# —————————————————————Division line ——————————————————————
a = [0] * N
b = [0] * N


def check(mid):
    cnt = m
    for i in range(1, n + 1):
        if b[i] < mid - a[i]:
            return False
        if a[i] < mid:
            cnt -= (mid - a[i])
        if cnt < 0:
            return False
    return True


n, m = read()
a[1:] = read()
b[1:] = read()

l, r = min(a), max(a)

while l < r:
    mid = (l + r + 1) >> 1
    if check(mid):
        l = mid
    else:
        r = mid - 1

print(r)
