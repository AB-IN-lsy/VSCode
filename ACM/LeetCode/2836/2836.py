'''
Author: NEFU AB-IN
Date: 2024-07-27 10:24:54
FilePath: \LeetCode\2836\2836.py
LastEditTime: 2024-07-27 14:37:16
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
            pa = [[(p, p)] + Arr.array((-1, -1), m - 1) for p in parent]  # pa[x][0] = x
            for i in range(m):
                for x in range(n):
                    p, s = pa[x][i]  # Get the 2^i-th ancestor of node x
                    pp, ss = pa[p][i]  # Get the 2^i-th ancestor of p, which will be the 2^(i+1)-th ancestor of x
                    pa[x][i + 1] = (pp, ss + s)  # Set the 2^(i+1)-th ancestor of x
            self.pa = pa


# ————————————————————— Division line ——————————————————————
class Solution:
    def getMaxFunctionValue(self, receiver: List[int], k: int) -> int:
        ta = Std.TreeAncestor(len(receiver), k.bit_length(), receiver)
        ans = 0
        for i in range(ta.n):
            sum_ = i
            node = i
            for j in range(ta.m):
                if (1 << j) & k:
                    node, s = ta.pa[node][j]
                    sum_ += s
            ans = Math.max(ans, sum_)
        return ans
