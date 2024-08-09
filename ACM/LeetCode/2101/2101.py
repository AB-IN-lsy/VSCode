'''
Author: NEFU AB-IN
Date: 2024-07-22 19:30:24
FilePath: \LeetCode\2101\2101.py
LastEditTime: 2024-07-23 10:22:15
'''
# 3.8.19 import
import random
from collections import Counter, defaultdict, deque
from datetime import datetime, timedelta
from functools import lru_cache
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from itertools import combinations, compress, permutations, starmap, tee
from math import ceil, comb, fabs, floor, gcd, hypot, log, perm, sqrt
from string import ascii_lowercase, ascii_uppercase
from sys import exit, setrecursionlimit, stdin
from typing import Any, Dict, List, Optional, Tuple, TypeVar, Union

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
    class GraphShortestPath:
        def __init__(self, n: int):
            self.n = n
            self.g = Arr.graph(n)
            self.spfa_cache = {}
            self.dijkstra_cache = {}
            self.floyd_cache = None

        def add_edge(self, u: int, v: int, w: int):
            """Add an edge to the graph."""
            self.g[u].append((v, w))

        def floyd_01(self) -> List[int]:
            """Floyd's algorithm for finding reachability between all pairs of nodes using bitwise operations."""
            n = self.n
            # Initialize reachability bitsets
            f = Arr.array(0, n)
            for u in range(n):
                f[u] |= 1 << u  # Each node can reach itself
                for v, w in self.g[u]:
                    f[u] |= 1 << v  # Add reachable nodes based on edges

            # Floyd-Warshall algorithm for reachability
            for k in range(n):
                for i in range(n):
                    if f[i] >> k & 1:  # If i can reach k
                        f[i] |= f[k]  # Then i can also reach all nodes k can reach

            return f


class Bit(int):
    def __new__(cls, value):
        return super(Bit, cls).__new__(cls, value)

    def __init__(self, value):
        self.bin_rep = bin(value)[2:]

    def bit_length(self): return len(self.bin_rep)
    def bit_count(self): return self.bin_rep.count('1')
    def lowest1(self): return Bit(self & -self)
    def lowest0(self): return Bit(~self & (self + 1))
    def clear_lowest1(self): return Bit(self & (self - 1))
    def clear_lowest0(self): return Bit(self | (self + 1))
    def get_bits(self, start, end): return self & Bit.range_mask(start, end)

    all_ones_mask = staticmethod(lambda length: (1 << length) - 1)
    all_zeros_mask = staticmethod(lambda length: 0)
    single_bit_mask = staticmethod(lambda position: 1 << position)
    range_mask = staticmethod(lambda start, end: ((1 << (end - start + 1)) - 1) << start)

# ————————————————————— Division line ——————————————————————


class Solution:
    def maximumDetonation(self, bombs) -> int:

        def check(bomb_x, bomb_y):
            _, x1, y1, r1 = bomb_x
            _, x2, y2, r2 = bomb_y
            dist = hypot(x2 - x1, y2 - y1)
            return dist <= r1

        n = len(bombs)
        g = Arr.graph(n)
        bombs = [(i, *bomb) for i, bomb in enumerate(bombs)]
        for bomb_x, bomb_y in permutations(bombs, 2):
            if check(bomb_x, bomb_y):
                g[bomb_x[0]].append(bomb_y[0])

        def dfs(u):
            nonlocal cnt
            vis[u] = True
            for v in g[u]:
                if not vis[v]:
                    cnt += 1
                    dfs(v)

        max_ = 1
        for i in range(n):
            cnt = 1
            vis = Arr.array(False, n)
            dfs(i)
            max_ = Math.max(max_, cnt)
        return max_

    def maximumDetonation(self, bombs) -> int:
        def check(bomb_x, bomb_y):
            _, x1, y1, r1 = bomb_x
            _, x2, y2, r2 = bomb_y
            dist = hypot(x2 - x1, y2 - y1)
            return dist <= r1

        n = len(bombs)
        g = Std.GraphShortestPath(n)
        bombs = [(i, *bomb) for i, bomb in enumerate(bombs)]
        for bomb_x, bomb_y in permutations(bombs, 2):
            if check(bomb_x, bomb_y):
                g.add_edge(bomb_x[0], bomb_y[0], 0)

        dist = g.floyd_01()
        return max(Bit(s).bit_count() for s in dist)
