'''
Author: NEFU AB-IN
Date: 2023-05-25 16:55:03
FilePath: \LanQiao\2188\2188.py
LastEditTime: 2023-05-25 17:51:13
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
cnt = 12 * 60 * 60  # 360度走多少秒

s_j = 360 / cnt
f_j = 360 * 24 / cnt
m_j = 360 * 24 * 60 / cnt

for i in range(cnt * 2):  # 由于24小时，时钟要跑两遍，所以乘2
    s, f, m = s_j * i % 360, f_j * i % 360, m_j * i % 360
    sf = fabs(s - f)
    fm = fabs(f - m)

    if sf > 180:
        sf -= 180
    if fm > 180:
        fm -= 180

    if fabs(sf - 2 * fm) < 1e-8:
        s, f, m = i // 3600, i % 3600 // 60, i % 60
        if s <= 6 and not (s == 0 and f == 0 and m == 0):
            print(s, f, m)
