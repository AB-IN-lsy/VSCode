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
dirs1 = [(-1, 0), (0, 1), (1, 0), (0, -1)]
dirs2 = [(-1, 1), (1, 1), (1, -1), (-1, -1)]

class neighborSum:

    def __init__(self, grid: List[List[int]]):
        self.n = len(grid)
        self.g = grid
        self.d = {}
        for i in range(self.n):
            for j in range(self.n):
                self.d[grid[i][j]] = (i, j)

    def adjacentSum(self, value: int) -> int:
        i, j = self.d[value]
        ans = 0
        for dx, dy in dirs1:
            if 0 <= i + dx < self.n and 0 <= j + dy < self.n:
                ans += self.g[i+dx][j+dy]
        return ans

    def diagonalSum(self, value: int) -> int:
        i, j = self.d[value]
        ans = 0
        for dx, dy in dirs2:
            if 0 <= i + dx < self.n and 0 <= j + dy < self.n:
                ans += self.g[i+dx][j+dy]
        return ans