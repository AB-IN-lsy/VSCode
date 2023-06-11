'''
Author: NEFU AB-IN
Date: 2023-06-09 18:00:12
FilePath: \LanQiao\2940\2940.py
LastEditTime: 2023-06-09 20:26:52
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
        return self.y < a.y


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
dp = [[0] * M for _ in range(N)]
Log = [0] * N
a = [0] * N


def init():
    for j in range(M):
        i = 1
        while i + (1 << j) - 1 <= n:
            if j == 0:
                dp[i][j] = a[i]
            else:
                dp[i][j] = gcd(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1])
            i += 1
    for i in range(2, N):
        Log[i] = Log[i // 2] + 1


def query(l, r):
    k = Log[r - l + 1]
    return gcd(dp[l][k], dp[r - (1 << k) + 1][k])


n, = read()
a[1:] = read()

ans = []
init()

for i in range(1, n + 1):
    l, r = i, n
    while l < r:
        mid = l + r + 1 >> 1
        if query(i, mid) >= mid - i + 1:
            l = mid
        else:
            r = mid - 1
    if query(i, l) == l - i + 1:
        ans.append(sa(i, l))

cnt = 1
if len(ans) == 0:
    print(0)
else:
    ans.sort()
    tmp = ans[0].y
    for i in ans:
        if i.x > tmp:
            cnt += 1
            tmp = i.y
    print(cnt)
