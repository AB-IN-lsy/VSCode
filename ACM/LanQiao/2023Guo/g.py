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

read = lambda: map(int, input().split())
LTN = lambda x: ord(x.upper()) - 65
NTL = lambda x: ascii_uppercase[x]
AR = lambda x: [x] * N

# _____________________________________________________


# 得出结论 这个数列只有两种数字 只有aab abb两种组合 
# aab 满足 2 * a > b
# abb 满足 2 * b > a

# 问题转化为 将数组中的数字转换为a, b 代价最小 
# 思路 二分a 找b

# 暴力版本

a = AR(0)
n, = read()
a[1:] = read()

ans = INF

def check(p, q):
    # p为双边
    cnt = 0
    for i in range(1, n + 1):
        cnt += min(abs(a[i] - p), abs(a[i] - q))
    return cnt


l, r = min(a[1:]), max(a[1:])

for i in range(l, r + 1): # i双边
    for j in range(l, r + 1):
        if 2 * i > j and 2 * j > i:
            ans = min(ans, check(i, j))


print(ans)