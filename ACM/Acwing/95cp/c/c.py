'''
Author: NEFU AB-IN
Date: 2023-03-31 21:50:42
FilePath: \Acwing\95cp\c\c.py
LastEditTime: 2023-04-01 00:48:47
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


def solve():
    n, = read()
    a = list(read())
    x = min(a)
    print("Alice" if x != a[0] else "Bob")


for _ in range(int(input())):
    solve()