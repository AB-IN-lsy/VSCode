'''
Author: NEFU AB-IN
Date: 2023-03-31 15:43:02
FilePath: \Acwing\96cp\b\b.py
LastEditTime: 2023-03-31 16:26:21
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
class Ob(object):
    def __init__(self, l, h, v, w):
        self.l = l
        self.h = h
        self.v = v
        self.w = w

    def __lt__(self, x):
        return self.w / self.v > x.w / x.v


a = []
n, m, v0, w0 = read()
a.append(Ob(INF, 1, v0, w0))

for i in range(m):
    l, h, v, w = read()
    a.append(Ob(l, h, v, w))

a.sort()
ans = 0
for ob in a:
    l, h, v, w = ob.l, ob.h, ob.v, ob.w
    if h < n:
        # 不超重
        num = min(l // h, n // v)
        n -= num * v
        ans += num * w

print(ans)
