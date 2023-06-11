'''
Author: NEFU AB-IN
Date: 2023-06-09 20:48:56
FilePath: \LanQiao\3072\3072.py
LastEditTime: 2023-06-09 21:00:04
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
N = int(1e5 + 10)
M = 20
INF = int(2e9)

# Define
setrecursionlimit(INF)
input = lambda: stdin.readline().rstrip("\r\n")  # Remove when Mutiple data
read = lambda: map(int, input().split())
LTN = lambda x: ord(x.upper()) - 65  # A -> 0
NTL = lambda x: ascii_uppercase[x]  # 0 -> A

# —————————————————————Division line ——————————————————————
'''
Author: NEFU AB-IN
Date: 2022-03-07 22:28:25
FilePath: \ACM\Acwing\900.1.py
LastEditTime: 2022-03-07 22:31:58
'''
N = 1100
MOD = int(1e9 + 7)
dp = [[0] * N for _ in range(N)]  # 表示总和为i, 并且恰好为j个数的方案

n = int(input())
dp[0][0] = 1  #总和为0，恰好0个数的方案有一个

for i in range(1, n + 1):
    for j in range(1, n + 1):
        dp[i][j] = (dp[i - 1][j - 1] + dp[i - j][j]) % MOD

res = 0
for i in range(1, n + 1):
    res = (res + dp[n][i]) % MOD
print(res)