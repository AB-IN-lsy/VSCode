'''
Author: NEFU AB-IN
Date: 2024-08-07 10:04:41
FilePath: \LeetCode\3240\3240.py
LastEditTime: 2024-08-07 15:26:25
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

        def __init__(self, n):
            self.n = n
            self.parent = list(range(n))  # Parent pointers
            self.rank = Arr.array(1, n)  # Rank (approximate tree height)
            self.size = Arr.array(1, n)  # Size arrays for each node
            self.cnt_1 = Arr.array(0, n)

        def find(self, p):
            """Find the root of the element p with path compression."""
            if self.parent[p] != p:
                self.parent[p] = self.find(self.parent[p])  # Path compression
            return self.parent[p]

        def union(self, p, q):
            """Union the sets containing p and q using union by rank and merge data if available."""
            rootP = self.find(p)
            rootQ = self.find(q)

            if rootP != rootQ:
                # Union by rank
                if self.rank[rootP] > self.rank[rootQ]:
                    self.parent[rootQ] = rootP
                    self.size[rootP] += self.size[rootQ]
                    self.cnt_1[rootP] += self.cnt_1[rootQ]
                    return rootP
                elif self.rank[rootP] < self.rank[rootQ]:
                    self.parent[rootP] = rootQ
                    self.size[rootQ] += self.size[rootP]
                    self.cnt_1[rootQ] += self.cnt_1[rootP]
                    return rootQ
                else:
                    self.parent[rootQ] = rootP
                    self.size[rootP] += self.size[rootQ]
                    self.cnt_1[rootP] += self.cnt_1[rootQ]
                    self.rank[rootP] += 1
                    return rootP
            return rootP  # They are already in the same set

# ————————————————————— Division line ——————————————————————


class Solution:
    def minFlips(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        uf = Std.UnionFind(m * n)

        def index(i, j): return i * n + j

        for i in range(m):
            for j in range(n):
                uf.cnt_1[index(i, j)] = grid[i][j]

        for i in range(m):
            for j in range(n):
                uf.union(index(i, j), index(i, n - j - 1))
                uf.union(index(i, j), index(m - i - 1, j))

        dp = [0, INF, INF, INF]  # dp[i]表示：1的数量%4=i的最小操作次数
        for i in range(m):
            for j in range(n):
                if uf.find(index(i, j)) == index(i, j):
                    f = [INF] * 4
                    for x in range(4):  # 每个连通块内，要么全1，要么全0
                        # 全变为0，则需要将该连通块的所有1翻转
                        f[(x + 0) % 4] = Math.min(f[(x + 0) % 4], dp[x] + uf.cnt_1[index(i, j)])
                        # 全变为1，则需要将该连通块的所有0翻转,0的数量是总数量减1的数量
                        f[(x + uf.size[index(i, j)]) % 4] = Math.min(f[(x + uf.size[index(i, j)]) % 4], dp[x] + uf.size[index(i, j)] - uf.cnt_1[index(i, j)])
                    dp = f
        return dp[0]
