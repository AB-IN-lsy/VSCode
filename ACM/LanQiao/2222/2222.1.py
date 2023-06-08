'''
Author: NEFU AB-IN
Date: 2023-05-25 15:59:24
FilePath: \LanQiao\2222\2222.1.py
LastEditTime: 2023-05-25 16:35:58
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
    def __init__(self, x, y, w):
        self.x = x
        self.y = y
        self.w = w


# Final
N = int(2e3 + 10)
M = int(5e6 + 10)
INF = int(2e9)

# Define
setrecursionlimit(INF)
input = lambda: stdin.readline().rstrip("\r\n")  # Remove when Mutiple data
read = lambda: map(int, input().split())
LTN = lambda x: ord(x.upper()) - 65  # A -> 0
NTL = lambda x: ascii_uppercase[x]  # 0 -> A

# —————————————————————Division line ——————————————————————

dx = [0, -1, 0, 1]
dy = [-1, 0, 1, 0]

g = [[] for _ in range(M)]
dist = [[0] * N for _ in range(N)]
st = [[0] * N for _ in range(N)]


def pos_to_num(x, y):
    x -= 1
    y -= 1
    return x * n + y


def num_to_pos(num):
    return [num // n + 1, num % n + 1]


n, m = read()
for i in range(m):
    x1, y1, x2, y2 = read()
    g[pos_to_num(x1, y1)].append(pos_to_num(x2, y2))
    g[pos_to_num(x2, y2)].append(pos_to_num(x1, y1))


def bfs(sx, sy):
    q = deque()
    q.appendleft(sa(sx, sy, 0))
    st[sx][sy] = 1
    while len(q):
        t = q.pop()
        x, y, w = t.x, t.y, t.w
        for i in range(4):
            x1 = x + dx[i]
            y1 = y + dy[i]
            if x1 < 1 or x1 > n or y1 < 1 or y1 > n or st[x1][y1]:
                continue
            st[x1][y1] = 1
            q.appendleft(sa(x1, y1, w + 1))
            dist[x1][y1] = w + 1

        for num in g[pos_to_num(x, y)]:
            x1, y1 = num_to_pos(num)
            if st[x1][y1]:
                continue
            st[x1][y1] = 1
            q.appendleft(sa(x1, y1, w + 1))
            dist[x1][y1] = w + 1


ans = 0

bfs(n, n)

for i in range(1, n + 1):
    for j in range(1, n + 1):
        ans += dist[i][j]

print(f'{ans / (n * n):.2f}')