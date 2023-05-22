'''
Author: NEFU AB-IN
Date: 2023-05-18 17:20:27
FilePath: \Acwing\3498\3498.py
LastEditTime: 2023-05-18 18:31:46
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

while True:
    try:
        s = input()
        e = input()
        if s > e:
            s, e = e, s
        d1 = datetime(year=int(s[:4]), month=int(s[4:6]), day=int(s[6:]))
        d2 = datetime(year=int(e[:4]), month=int(e[4:6]), day=int(e[6:]))

        print((d2 - d1).days + 1)
    except:
        break
