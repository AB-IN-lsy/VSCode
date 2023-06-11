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
        


N = int(5e3 + 10)
M = 20
INF = int(2e9)

read = lambda: map(int, input().split())
LTN = lambda x: ord(x.upper()) - 65
NTL = lambda x: ascii_uppercase[x]
AR = lambda x: [x] * N

# _____________________________________________________

w = AR(0)
n, a, b = read()
w[1:] = read()

def init(a, b):
    w1, dpa, dpb, st = AR(0), AR(0), AR(0), AR(0)
    dp = [[] for _ in range(N)] 

    for i in range(1, n + 1):
        for j in range(a, w[i] - 1, -1):
            if dpa[j - w[i]] + w[i] > dpa[j]:
                dpa[j] = dpa[j - w[i]] + w[i]
                dp[j] = dp[j - w[i]][:]
                dp[j].append(i)

    for i in dp[a]:
        st[i] = 1


    for i in range(1, n + 1):
        if st[i] == 0:
            w1[i] = w[i]

    for i in range(1, n + 1):
        for j in range(b, w1[i] - 1, -1):
            if dpb[j - w1[i]] + w1[i] > dpb[j]:
                dpb[j] = dpb[j - w1[i]] + w1[i]

    return dpa[a] + dpb[b]


# ____先a后b
# ____先b后a
print(max(init(a, b), init(b, a)))
