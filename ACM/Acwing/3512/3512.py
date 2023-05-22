'''
Author: NEFU AB-IN
Date: 2023-05-20 20:32:18
FilePath: \Acwing\3512\3512.py
LastEditTime: 2023-05-22 21:31:29
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

res = 0
dis = [[0] * N for _ in range(N)]
n, = read()

for i in range(1, n + 1):
    dis[i][1:] = read()

for k in range(n, 1, -1): # 若k=1 代表把k为1的点也算进去了
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j])
            if i >= k and j >= k:
                res += dis[i][j]

print(res)