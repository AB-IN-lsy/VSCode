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

a = AR(0)
n, p, q = read()
a[1:] = read()

ans = abs(a[p] - a[q])

for i in range(1, n + 1):
    for j in range(i + 1, n + 1):
        if i > p and j < q:
            continue

        b = sorted(a[i : j + 1])
        an = a[:i] + b + a[j+1 :]
        ans = max(ans, abs(an[p] - an[q]))
print(ans)
