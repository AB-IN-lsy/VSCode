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


class Solution:
    def minFlips(self, grid: List[List[int]]) -> int:

        def flip(arr):
            n = len(arr)
            flips, one = 0, 0
            for i in range(n // 2):
                if arr[i] != arr[n - i - 1]:
                    flips += 1
                    arr[i] = arr[n - i - 1] = 1
                    one += 1
            return flips

        m, n = len(grid), len(grid[0])
        one_cnt = sum(sum(row) for row in grid)
        row_flips, row_one = sum(flip(grid[i]) for i in range(m))
        col_flips, col_one = sum(flip([grid[i][j] for i in range(m)]) for j in range(n))
        flips = row_flips + col_flips
        one_cnt += row_one + col_one

        if one_cnt % 4 == 0:
            return flips
