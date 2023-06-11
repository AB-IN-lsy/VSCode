from sys import setrecursionlimit, stdin, stdout, exit
from collections import Counter, deque
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from bisect import bisect_left, bisect_right
from datetime import datetime, timedelta
from string import ascii_lowercase, ascii_uppercase
from math import log, ceil, gcd, sqrt, fabs


class sa:
    def __init__(self, x , y):
        self.x = x
        self.y = y
    def __lt__(self, a):
        return self.x < a.x
        


N = int(2e5 + 10)
M = 20
INF = int(2e9)

setrecursionlimit(INF)
input = lambda: stdin.readline().rstrip("\r\n")
read = lambda: map(int, input().split())
LTN = lambda x: ord(x.upper()) - 65
NTL = lambda x: ascii_uppercase[x]
AR = lambda x: [x] * N

# _____________________________________________________


# 最小值的两倍 > 数组最大值
# 暴力版本

a = AR(0)
n, = read()
a[1:] = read()

ans = INF

def f(p, q):
    cnt = 0
    for i in range(1, n + 1):
        if a[i] < p:
            cnt += p - a[i]
        if a[i] == mx:
            cnt += abs(mx - q)
    return cnt

# 遍历最小值，二分最大值
mn, mx = min(a[1:]), max(a[1:])

for i in range(mn, mx + 1):
    l, r = i, 2 * i - 1
    for j in range(l, r + 1):
        if j > mx:
            break
        ans = min(ans, f(i, j))

print(ans)