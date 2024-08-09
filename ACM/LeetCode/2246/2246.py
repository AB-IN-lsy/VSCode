'''
Author: NEFU AB-IN
Date: 2024-08-07 16:39:57
FilePath: \LeetCode\2246\2246.py
LastEditTime: 2024-08-07 17:41:14
'''
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
    def longestPath(self, parent: List[int], s: str) -> int:
        g = Arr.graph(len(s))

        for i, fa in enumerate(parent):
            if fa == -1:
                continue
            g[fa].append((i, 1))

        ans = 0
        status = Arr.array(0, len(s))

        @lru_cache(None)
        def dfs(u):
            status[u] = 1
            max1, max2 = 0, 0
            nonlocal ans
            for v, w in g[u]:
                depth = dfs(v) + w
                if depth > max1 and s[v] != s[u]:
                    max2 = max1
                    max1 = depth
                elif depth > max2 and s[v] != s[u]:
                    max2 = depth

            ans = Math.max(ans, max1 + max2)
            return max1

        dfs(0)
        dfs.cache_clear()
        return ans + 1
