'''
Author: NEFU AB-IN
Date: 2023-04-27 10:26:31
FilePath: \Acwing\3473\3473.py
LastEditTime: 2023-04-27 10:36:42
'''
# import
import sys, math
from collections import Counter, deque
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from bisect import bisect_left, bisect_right
from datetime import datetime, timedelta
from string import ascii_lowercase, ascii_uppercase


class sa:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __lt__(self, x):
        pass


# Final
N = int(1e3 + 10)
INF = int(2e9)

# Define
sys.setrecursionlimit(INF)
input = lambda: sys.stdin.readline().rstrip("\r\n")  # Remove when Mutiple data
read = lambda: map(int, input().split())
letterTonumber = lambda x: ord(x.upper()) - 64

# —————————————————————Division line ——————————————————————

# 2x + 4y = a
# x + y max

n, = read()
for _ in range(n):
    a, = read()
    mx, mn = 0, INF
    if a & 1:
        print(0, 0)
        continue
    a //= 2
    for x in range(a + 1):
        if (a - x) % 2 == 0:
            y = (a - x) // 2
            mx = max(mx, x + y)
            mn = min(mn, x + y)

    print(mn, mx)
