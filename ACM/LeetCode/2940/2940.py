'''
Author: NEFU AB-IN
Date: 2024-08-10 17:31:58
FilePath: \LeetCode\2940\2940.py
LastEditTime: 2024-08-10 20:54:02
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
    class SparseTable:
        def __init__(self, data: list, func=lambda x, y: x | y):
            """Initialize the Sparse Table with the given data and function."""
            self.func = func
            self.st = [list(data)]
            i, n = 1, len(self.st[0])
            while 2 * i <= n:
                pre = self.st[-1]
                self.st.append([func(pre[j], pre[j + i]) for j in range(n - 2 * i + 1)])
                i <<= 1

        def query(self, begin: int, end: int):
            """Query the combined result over the interval [begin, end]."""
            lg = (end - begin + 1).bit_length() - 1
            return self.func(self.st[lg][begin], self.st[lg][end - (1 << lg) + 1])

# ————————————————————— Division line ——————————————————————


class Solution:
    def leftmostBuildingQueries(self, heights: List[int], queries: List[List[int]]) -> List[int]:
        n = len(heights)
        st = Std.SparseTable(heights, Math.max)

        ans = []
        for a, b in queries:
            if a > b:
                a, b = b, a
            if a == b or heights[b] > heights[a]:
                ans.append(b)
                continue

            val = Math.max(heights[a], heights[b])
            l, r = b, n - 1
            while l < r:
                mid = l + r >> 1
                if st.query(b, mid) > val:
                    r = mid
                else:
                    l = mid + 1
            ans.append(r if heights[r] > val else -1)
        return ans
