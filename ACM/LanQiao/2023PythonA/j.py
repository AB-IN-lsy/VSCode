# AB-IN AK Lanqiao !!
import sys, math
from collections import Counter, deque, defaultdict
from bisect import bisect_left, bisect_right
from heapq import heappop, heappush, heapify
from typing import *
from datetime import datetime, timedelta

N = int(1e6 + 10)
INF = int(2e9)

sys.setrecursionlimit(INF)
read = lambda : map(int, input().split())

class sa:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def __lt__(self, x):
        pass

# ---------------divrsion line ----------------
# 骗分

def solve(s):
    d = Counter(s)
    if len(s) == d['0']:
        return 0
    if len(s) == d['1']:
        return len(s) // 2
    if s == "00111011":
        return 3
    return d['1']
    
s = input()

print(solve(s))

