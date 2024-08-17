'''
Author: NEFU AB-IN
Date: 2024-08-15 00:34:10
FilePath: \LeetCode\3148\3148.py
LastEditTime: 2024-08-17 10:01:06
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
    class TreeAncestor:
        """
        Binary Lifting for Tree Ancestor Queries, allows us to find the 2^i-th ancestor of any node.
        Ensure that each node has only one edge pointing to another node to apply binary lifting.
        """

        def __init__(self, n: int, m: int, parent: List[int]):
            """
            Initializes the TreeAncestor with the given number of nodes and parent list.

            Args:
                n (int): Number of nodes.
                m (int): Maximum power of 2 to consider (default calculated based on n).
                parent (List[int]): List where parent[i] is the parent of node i.
            """
            # m = n.bit_length()
            self.n = n
            self.m = m
            pa = [[p] + Arr.array(-1, m - 1) for p in parent]  # pa[i][0] = p
            for i in range(m - 1):  # handle parent nodes exclude itself.
                for x in range(n):
                    p = pa[x][i]  # Get the 2^i-th ancestor of node x
                    if p != -1:
                        pp = pa[p][i]  # Get the 2^i-th ancestor of p, which will be the 2^(i+1)-th ancestor of x
                        pa[x][i + 1] = pp  # Set the 2^(i+1)-th ancestor of x
            self.pa = pa

        def get_kth_ancestor(self, node: int, k: int) -> int:
            """Returns the k-th ancestor of the given node (The starting node)."""
            for j in range(k.bit_length()):
                if (k >> j) & 1:
                    node = self.pa[node][j]
                    if node < 0:
                        break
            return node

# ————————————————————— Division line ——————————————————————


class Solution:
    def maxScore(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dp = Arr.array2d(INF, m + 1, n + 1)
        ans = -INF

        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                mn = Math.min(dp[i + 1][j], dp[i][j + 1])
                ans = Math.max(ans, x - mn)
                dp[i + 1][j + 1] = Math.min(mn, x)
        return ans


Solution().maxScore([[9, 5, 7, 3], [8, 9, 6, 1], [6, 7, 14, 3], [2, 5, 3, 1]])
