'''
Author: NEFU AB-IN
Date: 2024-07-17 18:58:41
FilePath: \LeetCode\1713\1713.1.py
LastEditTime: 2024-07-17 21:09:25
'''
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
from typing import Any, Dict, List, Tuple, TypeVar, Union

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
    class SegmentTree:
        """A Segment Tree implementation supporting range queries and updates.

        This Segment Tree can perform various operations such as sum, min, max,
        and supports point updates, range add, and range multiply updates.
        """
        class Node:
            def __init__(self, l: int = 0, r: int = 0):
                self.l = l
                self.r = r
                self.val = 0
                self.add_tag = 0
                self.mul_tag = 1

        def __init__(self, n: int, operation=lambda x, y: x + y, initial_value=0):
            """initial the tree, n can not be 0 !!!"""
            self.n = n
            self.tr = Arr.array(lambda: Std.SegmentTree.Node(0, 0), n << 2)
            self.operation = operation
            self.initial_value = initial_value

        def pushup(self, p: int):
            """Push up the values to the parent node based on the operation"""
            self.tr[p].val = self.operation(self.tr[p << 1].val, self.tr[p << 1 | 1].val)

        def pushdown(self, p: int):
            """Push down the tags to the children nodes"""
            if self.tr[p].add_tag != 0 or self.tr[p].mul_tag != 1:
                ls, rs = p << 1, p << 1 | 1
                if self.tr[p].mul_tag != 1:
                    self.apply(p, ls)
                    self.apply(p, rs)
                if self.tr[p].add_tag != 0:
                    self.apply(p, ls)
                    self.apply(p, rs)
                self.tr[p].add_tag = 0
                self.tr[p].mul_tag = 1

        def apply(self, p: int, child: int):
            """Apply the tags to a child node"""
            self.tr[child].val = self.tr[child].val * self.tr[p].mul_tag + self.tr[p].add_tag * (self.tr[child].r - self.tr[child].l + 1)
            self.tr[child].mul_tag *= self.tr[p].mul_tag
            self.tr[child].add_tag = self.tr[child].add_tag * self.tr[p].mul_tag + self.tr[p].add_tag

        def build(self, p: int, l: int, r: int, a: list = []):
            """Build the segment tree based on the given array or default value"""
            self.tr[p].l = l
            self.tr[p].r = r
            if l == r:
                self.tr[p].val = a[l] if a else self.initial_value
                return
            mid = (l + r) >> 1
            self.build(p << 1, l, mid, a)
            self.build(p << 1 | 1, mid + 1, r, a)
            self.pushup(p)

        def update_point(self, p: int, idx: int, value: int):
            """Point update for the segment tree at index idx"""
            if self.tr[p].l == self.tr[p].r:
                self.tr[p].val = value
                return
            mid = (self.tr[p].l + self.tr[p].r) >> 1
            if idx <= mid:
                self.update_point(p << 1, idx, value)
            else:
                self.update_point(p << 1 | 1, idx, value)
            self.pushup(p)

        def update_range_add(self, p: int, l: int, r: int, d: int):
            """Range add update for the segment tree within the range [l, r]"""
            if l <= self.tr[p].l and self.tr[p].r <= r:
                self.tr[p].val += d * (self.tr[p].r - self.tr[p].l + 1)
                self.tr[p].add_tag += d
                return
            self.pushdown(p)
            mid = (self.tr[p].l + self.tr[p].r) >> 1
            if l <= mid:
                self.update_range_add(p << 1, l, r, d)
            if mid < r:
                self.update_range_add(p << 1 | 1, l, r, d)
            self.pushup(p)

        def update_range_mul(self, p: int, l: int, r: int, d: int):
            """Range multiply update for the segment tree within the range [l, r]"""
            if l <= self.tr[p].l and self.tr[p].r <= r:
                self.tr[p].val *= d
                self.tr[p].mul_tag *= d
                self.tr[p].add_tag *= d
                return
            self.pushdown(p)
            mid = (self.tr[p].l + self.tr[p].r) >> 1
            if l <= mid:
                self.update_range_mul(p << 1, l, r, d)
            if mid < r:
                self.update_range_mul(p << 1 | 1, l, r, d)
            self.pushup(p)

        def query(self, p: int, l: int, r: int) -> int:
            """Query the segment tree within the range [l, r]"""
            if l <= self.tr[p].l and self.tr[p].r <= r:
                return self.tr[p].val
            self.pushdown(p)
            mid = (self.tr[p].l + self.tr[p].r) >> 1
            res = self.initial_value
            if l <= mid:
                res = self.operation(res, self.query(p << 1, l, r))
            if r > mid:
                res = self.operation(res, self.query(p << 1 | 1, l, r))
            return res

        @staticmethod
        def discretize(array):
            """Discretize the array and return the mapping dictionary. Index starts from 1"""
            sorted_unique = sorted(set(array))
            mapping = {val: idx + 1 for idx, val in enumerate(sorted_unique)}
            return [mapping[val] for val in array], mapping
# ————————————————————— Division line ——————————————————————


class Solution:
    def minOperations(self, target: List[int], arr: List[int]) -> int:
        map_ = Counter()
        for i in range(len(target)):
            map_[target[i]] = i
        arr = [map_[num] for num in arr if num in map_]
        n = len(arr)

        if not arr:
            return len(target)

        discretized_arr, mapping = Std.SegmentTree.discretize(arr)
        seg = Std.SegmentTree(n, Math.max, 0)
        seg.build(1, 0, n - 1)
        for val in discretized_arr:
            max_val = seg.query(1, 0, val - 1) + 1
            seg.update_point(1, val, max_val)
        return len(target) - seg.query(1, 0, n - 1)
