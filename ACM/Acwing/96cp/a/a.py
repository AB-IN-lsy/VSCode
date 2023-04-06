'''
Author: NEFU AB-IN
Date: 2023-03-31 15:43:02
FilePath: \Acwing\96cp\a\a.py
LastEditTime: 2023-03-31 15:43:33
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
print(n // 2520)