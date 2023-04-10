'''
Author: NEFU AB-IN
Date: 2023-04-08 14:15:52
FilePath: \Vscode\ACM\LanQiao\2023PythonA\a.py
LastEditTime: 2023-04-08 14:19:47
'''
# AB-IN AK Lanqiao !!
# http://222.27.161.91/home.page
# aR7H4tDF
import sys, math
from collections import Counter, deque, defaultdict
from bisect import bisect_left, bisect_right
from heapq import heappop, heappush, heapify
from typing import *
from datetime import datetime, timedelta

N = int(1e6 + 10)
INF = int(2e9)

sys.setrecursionlimit(INF)
read = lambda: map(int, input().split())


class sa:
    def __init__(self, y, m, d):
        self.y = y
        self.m = m
        self.d = d

    def __lt__(self, x):
        pass


# ---------------divrsion line ----------------

# t1 = datetime(2000, 1, 1)
# t2 = datetime(2000, 1, 2)

# ans = 0
# while True:
#     if t1.year % t1.month == 0 and t1.year % t1.day == 0:
#         ans += 1
#     t1 = t1 + timedelta(days=1)
#     if t1 == t2:
#         break
# print(ans)

mouths = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]


def func(t1):
    y, m, d = t1.y, t1.m, t1.d
    if (y % 4 == 0 and y % 100) or (y % 400 == 0):
        mouths[2] = 29
    d += 1
    if d > mouths[m]:
        d = 1
        m += 1
    if m > 12:
        m = 1
        y += 1
    return sa(y, m, d)


t1 = sa(2000, 1, 1)
t2 = sa(2000000, 1, 2)

ans = 0
while True:
    if t1.y % t1.m == 0 and t1.y % t1.d == 0:
        ans += 1
    t1 = func(t1)
    if t1.y == t2.y and t1.m == t2.m and t1.d == t2.d:
        break
print(ans)

# 35830804