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
    def __init__(self, s, step):
        self.s = s
        self.step = step
    def __lt__(self, x):
        pass

# ---------------divrsion line ----------------
# BFS暴力 不会剪枝 没证明剪枝一定正确

def solve():
    t = input()
    s = input()

    t = " " + t
    s = " " + s

    if t[1] != s[1] or t[-1] != s[-1]:
        return -1

    q = deque()
    q.appendleft(sa(s, 0))
    while len(q):
        tp = q.pop()
        s, step = tp.s, tp.step
        if s == t:
            return step
        for i in range(2, len(s) - 1):
            if s[i] == '0' and s[i - 1] == '1' and s[i + 1] == '1':
                g = s[:i - 1] + "111" + s[i + 2:]
                if g == t:
                    return step + 1
                q.appendleft(sa(g, step + 1))
            if s[i] == '1' and s[i - 1] == '0' and s[i + 1] == '0':
                g = s[:i - 1] + "000" + s[i + 2:]
                if g == t:
                    return step + 1
                q.appendleft(sa(g, step + 1))
    return -1


T, = read()
for _ in range(T):
    print(solve())