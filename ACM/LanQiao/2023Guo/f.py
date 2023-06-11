from sys import setrecursionlimit, stdin, stdout, exit
from collections import Counter, deque
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from bisect import bisect_left, bisect_right
from datetime import datetime, timedelta
from string import ascii_lowercase, ascii_uppercase
from math import log, ceil, gcd, sqrt, fabs


class sa:
    def __init__(self, x , y):
        self.x = x
        self.y = y
        


N = int(1010)
M = 20
INF = int(2e9)

read = lambda: map(int, input().split())
LTN = lambda x: ord(x.upper()) - 65
NTL = lambda x: ascii_uppercase[x]
AR = lambda x: [x] * N

# _____________________________________________________

g = [AR(0) for _ in range(N)]
n, = read()

for i in range(1, n + 1):
    g[i][1:] = read()


# 首先求每一行的每个点的可递增最长序列的长度，0代表走不动，1代表可走一格
# 首先求往右的

dpr, dpl = [AR(0) for _ in range(N)], [AR(0) for _ in range(N)]
for i in range(1, n + 1):
    for j in range(n - 1, 0, -1):
        if g[i][j] < g[i][j + 1]:
            dpr[i][j] = dpr[i][j + 1] + 1
        else:
            dpr[i][j] = 0

    for j in range(1, n + 1):
        if g[i][j] < g[i][j - 1]:
            dpl[i][j] = dpl[i][j - 1] + 1
        else:
            dpl[i][j] = 0

dist = [AR(INF) for _ in range(N)]
q = deque()

dx = [1, 0]
dy = [0, 1]

def bfs():
    dist[1][1] = 0
    q.appendleft(sa(1, 1))
    while len(q):
        point = q.pop()
        x, y = point.x, point.y

        for i in range(2):
            x1 = x + dx[i]
            y1 = y + dy[i]
            if x1 < 1 or x1 > n or y1 < 1 or y1 > n:
                continue
            if dist[x1][y1] > dist[x][y] + 1:
                dist[x1][y1] = dist[x][y] + 1
                if x1 == n and y1 == n:
                    return dist[x1][y1]
                q.appendleft(sa(x1, y1))
        
        l, r = dpl[x][y], dpr[x][y]
        if l != 0: 
            for i in range(1, l + 1):
                x1, y1 = x, y - i
                if x1 < 1 or x1 > n or y1 < 1 or y1 > n:
                    continue
                if dist[x1][y1] > dist[x][y] + 1:
                    dist[x1][y1] = dist[x][y] + 1
                    if x1 == n and y1 == n:
                        return dist[x1][y1]
                    q.appendleft(sa(x1, y1))
        if r != 0:
            for i in range(1, r + 1):
                x1, y1 = x, y + i
                if x1 < 1 or x1 > n or y1 < 1 or y1 > n:
                    continue
                if dist[x1][y1] > dist[x][y] + 1:
                    dist[x1][y1] = dist[x][y] + 1
                    if x1 == n and y1 == n:
                        return dist[x1][y1]
                    q.appendleft(sa(x1, y1))
    return dist[n][n]

print(bfs())