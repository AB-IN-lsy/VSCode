'''
Author: NEFU AB-IN
Date: 2023-03-26 10:40:31
FilePath: \Acwing\test\test.py
LastEditTime: 2023-05-18 18:45:06
'''
# import
import sys, math, os
from io import BytesIO, IOBase
from collections import Counter, deque
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from bisect import bisect_left, bisect_right
from datetime import datetime, timedelta
from typing import *


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
input = lambda: sys.stdin.readline().rstrip("\r\n")
read = lambda: map(int, input().split())

# —————————————————————Division line ——————————————————————

d1 = datetime(year=99998, month=1, day=1)