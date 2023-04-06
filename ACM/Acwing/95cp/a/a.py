'''
Author: NEFU AB-IN
Date: 2023-03-31 21:50:42
FilePath: \Acwing\95cp\a\a.py
LastEditTime: 2023-03-31 21:51:38
'''
# import
import sys, math
from collections import Counter, deque
from heapq import heappop, heappush
from bisect import bisect_left, bisect_right

# Final
N = int(1e3 + 10)
INF = int(2e9)

# Define
sys.setrecursionlimit(INF)
read = lambda: map(int, input().split())

# —————————————————————Division line ————————————————————————————————————————

x1, y1 = read()
x2, y2 = read()

print(max(abs(x1 - x2), abs(y1 - y2)))