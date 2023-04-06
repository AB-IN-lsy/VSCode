'''
Author: NEFU AB-IN
Date: 2023-04-01 20:20:04
FilePath: \Acwing\94cp\a\a.py
LastEditTime: 2023-04-01 20:24:15
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

n, = read()

print((n + 4) // 5)