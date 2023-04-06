'''
Author: NEFU AB-IN
Date: 2023-03-31 21:50:42
FilePath: \Acwing\95cp\b\b.py
LastEditTime: 2023-03-31 22:01:28
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


def solve(x):
    ans, i = 1, 2
    while i <= x // i:
        cnt = 0
        while x % i == 0:
            x //= i
            cnt += 1
        ans *= (cnt + 1)
        i += 1
    if x > 1:
        ans *= 2
    return ans


n, = read()
a = list(read())

for i in a:
    if solve(i) == 3:
        print("YES")
    else:
        print("NO")
