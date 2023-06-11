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

a, q, p = [0] * N, [0] * N, [0] * N

n, = read()
a[1:] = read()

for i in range(1, n + 1):
    q[i] = q[i - 1] + a[i]
    p[i] = p[i - 1] ^ a[i]


def check(l, r):
    return q[r] - q[l - 1] == p[r] ^ p[l - 1]


ans = 0
for i in range(1, n + 1):
    l, r = i, n
    while l < r:
        mid = l + r + 1 >> 1
        if check(i, mid):
            l = mid
        else:
            r = mid - 1
    if check(i, r):
        ans += (r - i + 1)
print(ans)
