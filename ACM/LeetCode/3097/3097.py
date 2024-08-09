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
    class bisect:
        @staticmethod
        def bisect_left(a, x, key=lambda y: y, lo=0, hi=None):
            """The insertion point is the first position where the element is not less than x."""
            if hi is None:
                hi = len(a)
            left, right = lo, hi
            while left < right:
                mid = (left + right) >> 1
                if key(a[mid]) < x:
                    left = mid + 1
                else:
                    right = mid
            return left

        @staticmethod
        def bisect_right(a, x, key=lambda y: y, lo=0, hi=None):
            """The insertion point is the first position where the element is greater than x."""
            if hi is None:
                hi = len(a)
            left, right = lo, hi
            while left < right:
                mid = (left + right) >> 1
                if key(a[mid]) <= x:
                    left = mid + 1
                else:
                    right = mid
            return left

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
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        st = Std.SparseTable(nums, lambda x, y: x | y)
        n = len(nums)
        res = INF
        left = 0
        for right in range(n):
            while left <= right and st.query(left, right) >= k:
                print(left, right)
                res = Math.min(res, right - left + 1)
                left += 1
        return res if res != INF else -1


print(Solution().minimumSubarrayLength([2, 6, 5, 3, 4, 7, 9], 4))
