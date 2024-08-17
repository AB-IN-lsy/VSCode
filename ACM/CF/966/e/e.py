# 3.8.19 import
import random
from collections import Counter, defaultdict, deque
from datetime import datetime, timedelta
from functools import lru_cache, reduce
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from itertools import combinations, compress, permutations, starmap, tee
from math import ceil, comb, fabs, floor, gcd, hypot, log, perm, sqrt
from string import ascii_lowercase, ascii_uppercase
from sys import exit, setrecursionlimit, stdin
from typing import Any, Callable, Dict, List, Optional, Tuple, TypeVar, Union

# Constants
TYPE = TypeVar('TYPE')
N = int(2e5 + 10)
M = int(20)
INF = int(1e12)
OFFSET = int(100)
MOD = int(1e9 + 7)

# Set recursion limit
setrecursionlimit(int(2e9))


class Arr:
    array = staticmethod(lambda x=0, size=N: [x() if callable(x) else x for _ in range(size)])
    array2d = staticmethod(lambda x=0, rows=N, cols=M: [Arr.array(x, cols) for _ in range(rows)])
    graph = staticmethod(lambda size=N: [[] for _ in range(size)])


class Math:
    max = staticmethod(lambda a, b: a if a > b else b)
    min = staticmethod(lambda a, b: a if a < b else b)


class IO:
    input = staticmethod(lambda: stdin.readline().rstrip("\r\n"))
    read = staticmethod(lambda: map(int, IO.input().split()))
    read_list = staticmethod(lambda: list(IO.read()))


class Std:
    pass

# ————————————————————— Division line ——————————————————————


def solve():
    n, m, k = IO.read()
    d, = IO.read()
    w = IO.read_list()

    matrix = Arr.array2d(0, n, m)

    diff = Arr.array2d(0, n + 1, m + 1)

    for x in range(n - k + 1):
        for y in range(m - k + 1):
            diff[x][y] += 1
            diff[x + k][y] -= 1
            diff[x][y + k] -= 1
            diff[x + k][y + k] += 1

    for i in range(n):
        for j in range(m):
            if i > 0:
                diff[i][j] += diff[i - 1][j]
            if j > 0:
                diff[i][j] += diff[i][j - 1]
            if i > 0 and j > 0:
                diff[i][j] -= diff[i - 1][j - 1]
            matrix[i][j] += diff[i][j]

    c = [item for sublist in matrix for item in sublist]
    c.sort(reverse=True)
    w.sort(reverse=True)

    ans = 0
    for i in range(min(len(c), len(w))):
        ans += c[i] * w[i]
    print(ans)


T, = IO.read()

for _ in range(T):
    solve()
