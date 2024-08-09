'''
Author: NEFU AB-IN
Date: 2024-07-14 10:28:41
FilePath: \LeetCode\CP406\c\c.py
LastEditTime: 2024-07-14 11:14:43
'''
# 3.8.19 import
import random
from collections import Counter, defaultdict, deque
from datetime import datetime, timedelta
from functools import lru_cache
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from itertools import combinations, compress, permutations, starmap, tee
from math import ceil, comb, fabs, floor, gcd, log, perm, sqrt
from string import ascii_lowercase, ascii_uppercase
from sys import exit, setrecursionlimit, stdin
from typing import Any, Dict, List, Tuple, TypeVar, Union

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
    def minimumCost(self, m: int, n: int, horizontalCut: List[int], verticalCut: List[int]) -> int:
        @lru_cache(None)
        def dfs(r1, c1, r2, c2):
            if r1 == r2 and c1 == c2:
                return 0

            min_cost = INF

            for i in range(r1, r2):
                cost = horizontalCut[i] + dfs(r1, c1, i, c2) + dfs(i + 1, c1, r2, c2)
                min_cost = Math.min(min_cost, cost)

            for j in range(c1, c2):
                cost = verticalCut[j] + dfs(r1, c1, r2, j) + dfs(r1, j + 1, r2, c2)
                min_cost = Math.min(min_cost, cost)

            return min_cost

        return dfs(0, 0, m - 1, n - 1)


print(Solution().minimumCost(3, 2, [1, 3], [5]))
