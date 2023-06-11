'''
Author: NEFU AB-IN
Date: 2023-06-09 23:46:37
FilePath: \LanQiao\2963\2963.py
LastEditTime: 2023-06-10 00:31:47
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

p = [0] * N

n, a, b = read()
p[1:] = read()

A, B, d = Counter(), Counter(), Counter()

for i in range(1, n + 1):
  d[p[i]] = 1

for i in range(1, n + 1):
    if d[p[i]] == 0:
        continue
    if d[a - p[i]] == 1 or A[a - p[i]] == 1:
        A[a - p[i]] = 1
        A[p[i]] = 1 
        d[a - p[i]] = 0
        d[p[i]] = 0
    elif d[b - p[i]] == 1 or B[b - p[i]] == 1:
        B[b - p[i]] = 1
        B[p[i]] = 1
        d[b - p[i]] = 0
        d[p[i]] = 0
    else:
        print("NO")
        exit(0)
    
print("YES")
for i in range(1, n + 1):
    if A[p[i]]:
        print(0, end = " ")
    else:
        print(1, end = " ")
