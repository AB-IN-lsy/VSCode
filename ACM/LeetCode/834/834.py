'''
Author: NEFU AB-IN
Date: 2024-08-06 20:52:10
FilePath: \LeetCode\834\834.py
LastEditTime: 2024-08-06 22:42:21
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
    class Graph:
        def __init__(self, n: int):
            self.n = n
            self.g = Arr.graph(n)
            self.depth = Arr.array(0, n)
            self.size = Arr.array(1, n)
            self.dist = Arr.array(0, n)

        def add_edge(self, u: int, v: int, w: int):
            """Add an edge to the graph."""
            self.g[u].append((v, w))

        def dfs1(self, u, fa):
            for v, w in self.g[u]:
                if fa == v:
                    continue
                self.depth[v] = self.depth[u] + w  # w = 1, 其实就是深度
                self.dfs1(v, u)
                self.size[u] += self.size[v]

        def dfs2(self, u, fa):
            for v, w in self.g[u]:
                if fa == v:
                    continue
                self.dist[v] = self.dist[u] + self.n - 2 * self.size[v]
                self.dfs2(v, u)
# ————————————————————— Division line ——————————————————————


class Solution:
    def sumOfDistancesInTree(self, n: int, edges: List[List[int]]) -> List[int]:
        g = Std.Graph(n)
        for u, v in edges:
            g.add_edge(u, v, 1)
            g.add_edge(v, u, 1)
        g.dfs1(0, -1)
        for i in range(n):  # 计算0结点到所有点的距离
            g.dist[0] += g.depth[i]
        g.dfs2(0, -1)
        return g.dist
