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
    def countGoodNodes(self, edges: List[List[int]]) -> int:
        n = len(edges) + 1
        g = Arr.graph(n)
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)

        subtree_size = Arr.array(0, n)

        def dfs(u, fa):
            size = 1
            for v in g[u]:
                if v != fa:
                    size += dfs(v, u)
            subtree_size[u] = size
            return size
        dfs(0, -1)
        ans = 0

        def dfs1(u, fa):
            nonlocal ans
            child_sizes = []
            for v in g[u]:
                if v != fa:
                    child_sizes.append(subtree_size[v])
            if len(child_sizes) > 0 and all(size == child_sizes[0] for size in child_sizes):
                ans += 1
            elif len(child_sizes) == 0:
                ans += 1

            for v in g[u]:
                if v != fa:
                    dfs1(v, u)

        dfs1(0, -1)
        return ans


Solution().countGoodNodes([[0, 1], [0, 2], [1, 3], [1, 4], [2, 5], [2, 6]])
