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
        


N = int(1e5 + 10)
M = 20
INF = int(2e9)

read = lambda: map(int, input().split())
LTN = lambda x: ord(x.upper()) - 65
NTL = lambda x: ascii_uppercase[x]
AR = lambda x: [x] * N

# _____________________________________________________

MOD = 998244353
fact = AR(0)

def init():
    fact[0] = 1
    for i in range(1, N):
        fact[i] = fact[i - 1] * i % MOD
    
init()
n, m = read()

a = n - 3 * m
b = m

fz = fact[a]
fm = pow(fact[a - b] * fact[b] % MOD, MOD - 2, MOD)

print(fz * fm * 10 % MOD)

