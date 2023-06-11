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

Log = AR(0)
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
