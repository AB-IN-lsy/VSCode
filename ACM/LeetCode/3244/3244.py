'''
Author: NEFU AB-IN
Date: 2024-08-09 22:27:53
FilePath: \LeetCode\3244\3244.py
LastEditTime: 2024-08-10 15:35:15
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
    class UnionFind:
        """Union-Find data structure."""

        def __init__(self, n: int):
            self.n = n
            self.comp_cnt = n  # Initially, each element is its own component
            self.parent = list(range(n))  # Parent pointers
            self.size = Arr.array(1, n)  # Size arrays for each node

        def find(self, p: int) -> int:
            """Find the root of the element p using non-recursive path compression."""
            rt = p
            while self.parent[rt] != rt:
                rt = self.parent[rt]
            while self.parent[p] != rt:
                self.parent[p], p = rt, self.parent[p]
            return rt

        def union(self, p: int, q: int) -> int:
            """Merge the set containing p into the set containing q."""
            rootP = self.find(p)
            rootQ = self.find(q)
            if rootP != rootQ:
                self.parent[rootP] = rootQ
                self.size[rootQ] += self.size[rootP]
                self.comp_cnt -= 1  # Decrease component count as two components are merged
            return rootQ

# ————————————————————— Division line ——————————————————————


class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        uf = Std.UnionFind(n - 1)
        ans = []

        for l, r in queries:
            l = uf.find(l)
            r = uf.find(r - 1)

            while l != r:
                uf.union(l, r)
                l = uf.find(l + 1)
            ans.append(uf.comp_cnt)
        return ans
