'''
Author: NEFU AB-IN
Date: 2024-07-29 10:43:55
FilePath: \LeetCode\699\699.1.py
LastEditTime: 2024-07-30 18:52:09
'''
# 3.8.19 import
import random
from collections import Counter, defaultdict, deque
from datetime import datetime, timedelta
from functools import lru_cache, reduce
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from itertools import combinations, compress, permutations, starmap, tee
from math import ceil, comb, fabs, floor, gcd, log, perm, sqrt
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
    class SegTree:
        """
        A segment tree based on dynamic binary tree algorithm. 
        Supports passing callback functions `f1` and `f2` to handle range queries (RMQ) such as range sum, 
        range maximum, and range minimum.
        """

        def __init__(self, f1: Callable, f2: Callable, l: int, r: int, v: int = 0):
            """
            Initializes the segment tree [left, right).
            Example functions:
                Segment Sum:
                    f1 = lambda a, b: a + b
                    f2 = lambda a, n: a * n
                Segment Maximum:
                    f1 = lambda a, b: Math.max(a, b)
                    f2 = lambda a, n: a
                Segment Minimum:
                    f1 = lambda a, b: Math.min(a, b)
                    f2 = lambda a, n: a
            Args:
                f1: Function for combining segment values. (merge values from different intervals)
                f2: Function for applying values to segments. (Spread a value to an interval)
                l (int): Left boundary of the segment.
                r (int): Right boundary of the segment.
                v (int): Initial value for the segment.
            """
            self.default = v  # Default value for the segments
            self.ans = f2(v, r-l)  # Current result of the segment
            self.f1 = f1
            self.f2 = f2
            self.l = l  # left
            self.r = r  # right
            self.v = v  # init value
            self.lazy_tag = 0  # Lazy tag
            self.left = None  # SubTree(left, bottom)
            self.right = None  # SubTree(right, bottom)

        @property
        def mid_h(self) -> int:
            """Returns the midpoint of the segment."""
            return self.l + self.r >> 1

        def _create_subtrees(self) -> None:
            """Creates left and right subtrees if they do not exist."""
            midh = self.mid_h
            if not self.left and midh > self.l:
                self.left = Std.SegTree(self.f1, self.f2, self.l, midh, self.default)
            if not self.right:
                self.right = Std.SegTree(self.f1, self.f2, midh, self.r, self.default)

        def build(self, arr: List[int]) -> int:
            """
            Initializes the segment tree with values from arr.

            Args:
                arr: List of values to initialize the segment tree.

            Returns:
                The combined value of the segment tree.
            """
            m0 = arr[0]
            self.lazy_tag = 0
            if self.r == self.l + 1:
                self.v = m0
                self.ans = self.f2(m0, len(arr))
                return self.ans
            self.v = '#'
            midh = self.mid_h
            self._create_subtrees()
            self.ans = self.f1(self.left.build(arr[:midh - self.l]), self.right.build(arr[midh - self.l:]))
            return self.ans

        def cover_seg(self, l: int, r: int, v: int) -> int:
            """
            Covers the segment [left, right) with value v.

            Args:
                l (int): Left boundary of the cover range.
                r (int): Right boundary of the cover range.
                v: Value to cover the segment with.

            Returns:
                The combined value of the segment tree.
            """
            if self.v == v or l >= self.r or r <= self.l:
                return self.ans
            if l <= self.l and r >= self.r:
                self.v = v
                self.lazy_tag = 0
                self.ans = self.f2(v, self.r - self.l)
                return self.ans
            self._create_subtrees()
            if self.v != '#':
                if self.left:
                    self.left.v = self.v
                    self.left.ans = self.f2(self.v, self.left.r - self.left.l)
                if self.right:
                    self.right.v = self.v
                    self.right.ans = self.f2(self.v, self.right.r - self.right.l)
                self.v = '#'
            # push up
            self.ans = self.f1(self.left.cover_seg(l, r, v), self.right.cover_seg(l, r, v))
            return self.ans

        def inc_seg(self, l: int, r: int, v: int) -> int:
            """
            Increases the segment [left, right) by value v.

            Args:
                l (int): Left boundary of the increase range.
                r (int): Right boundary of the increase range.
                v: Value to increase the segment by.

            Returns:
                The combined value of the segment tree.
            """
            if v == 0 or l >= self.r or r <= self.l:
                return self.ans
            if l <= self.l and r >= self.r:
                if self.v == '#':
                    self.lazy_tag += v
                else:
                    self.v += v
                self.ans += self.f2(v, self.r - self.l)
                return self.ans
            self._create_subtrees()
            if self.v != '#':
                self.left.v = self.v
                self.left.ans = self.f2(self.v, self.left.r - self.left.l)
                self.right.v = self.v
                self.right.ans = self.f2(self.v, self.right.r - self.right.l)
                self.v = '#'
            self._pushdown()
            self.ans = self.f1(self.left.inc_seg(l, r, v), self.right.inc_seg(l, r, v))
            return self.ans

        def inc_idx(self, idx: int, v: int) -> int:
            """
            Increases the value at index idx by value v.

            Args:
                idx (int): Index to increase.
                v: Value to increase by.

            Returns:
                The combined value of the segment tree.
            """
            if v == 0 or idx >= self.r or idx < self.l:
                return self.ans
            if idx == self.l == self.r - 1:
                self.v += v
                self.ans += self.f2(v, 1)
                return self.ans
            self._create_subtrees()
            if self.v != '#':
                self.left.v = self.v
                self.left.ans = self.f2(self.v, self.left.r - self.left.l)
                self.right.v = self.v
                self.right.ans = self.f2(self.v, self.right.r - self.right.l)
                self.v = '#'
            self._pushdown()
            self.ans = self.f1(self.left.inc_idx(idx, v), self.right.inc_idx(idx, v))
            return self.ans

        def _pushdown(self) -> None:
            """Propagates the lazy tag to the child nodes."""
            if self.lazy_tag != 0:
                if self.left:
                    if self.left.v != '#':
                        self.left.v += self.lazy_tag
                        self.left.lazy_tag = 0
                    else:
                        self.left.lazy_tag += self.lazy_tag
                    self.left.ans += self.f2(self.lazy_tag, self.left.r - self.left.l)
                if self.right:
                    if self.right.v != '#':
                        self.right.v += self.lazy_tag
                        self.right.lazy_tag = 0
                    else:
                        self.right.lazy_tag += self.lazy_tag
                    self.right.ans += self.f2(self.lazy_tag, self.right.r - self.right.l)
                self.lazy_tag = 0

        def query(self, l: int, r: int) -> int:
            """
            Queries the range [left, right) for the combined value.

            Args:
                l (int): Left boundary of the query range.
                r (int): Right boundary of the query range.

            Returns:
                The combined value of the range.
            """
            if l >= r:
                return 0
            if l <= self.l and r >= self.r:
                return self.ans
            if self.v != '#':
                return self.f2(self.v, Math.min(self.r, r) - Math.max(self.l, l))  # the overlapping length
            midh = self.mid_h
            anss = []
            if l < midh:
                anss.append(self.left.query(l, r))
            if r > midh:
                anss.append(self.right.query(l, r))
            return reduce(self.f1, anss)

        @staticmethod
        def discretize(array):
            """Discretize the array and return the mapping dictionary. Index starts from 1"""
            sorted_unique = sorted(set(array))
            mapping = {val: idx + 1 for idx, val in enumerate(sorted_unique)}
            return [mapping[val] for val in array], mapping

# ————————————————————— Division line ——————————————————————


class Solution:
    def fallingSquares(self, positions: List[List[int]]) -> List[int]:
        arr = []
        for x, len_ in positions:
            arr.append(x)
            arr.append(x + len_)

        arr, map_ = Std.SegTree.discretize(arr)
        n = len(arr) + 1

        def f1(a, b): return Math.max(a, b)
        def f2(a, n): return a

        seg = Std.SegTree(f1, f2, 0, n)
        ans = []
        max_ = 0
        for x, len_ in positions:
            l, r = map_[x], map_[x + len_]
            h = seg.query(l, r)
            h2 = h + len_
            seg.cover_seg(l, r, h2)
            max_ = Math.max(max_, h2)
            ans.append(max_)
        return ans


print(Solution().fallingSquares([[1, 2], [2, 3], [6, 1]]))
