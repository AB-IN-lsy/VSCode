'''
Author: NEFU AB-IN
Date: 2024-07-15 14:58:34
FilePath: \LeetCode\1713\1713.py
LastEditTime: 2024-07-17 19:03:13
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

    class BinaryTree:
        """Binary Indexed Tree (Fenwick Tree) for efficient prefix sum and range queries, with optional custom operation tracking."""

        def __init__(self, n, operation=lambda x, y: x + y, initial_value=0, array=None):
            self.n = n
            self.operation = operation
            self.initial_value = initial_value
            self.tree = Arr.array(initial_value, self.n + 1)

            if array:
                for i, value in enumerate(array, 1):
                    self.update(i, value)

        def update(self, i, value):
            """Update the value at index i."""
            while i <= self.n:
                self.tree[i] = self.operation(self.tree[i], value)
                i += i & -i

        def query(self, i):
            """Query the result of the operation up to index i."""
            result = self.initial_value
            while i > 0:
                result = self.operation(result, self.tree[i])
                i -= i & -i
            return result

        def range_query(self, l, r):
            """Query the result of the operation from index l to r."""
            return self.query(r) - self.query(l - 1)

        @staticmethod
        def discretize(array):
            """Discretize the array and return the mapping dictionary. Index starts from 1"""
            sorted_unique = sorted(set(array))
            mapping = {val: idx + 1 for idx, val in enumerate(sorted_unique)}
            return [mapping[val] for val in array], mapping

    class DifferenceBinaryTree:
        """Difference Array using Binary Indexed Tree (Fenwick Tree) for range updates and point queries."""

        def __init__(self, n, array=None):
            if array is None:
                array = []
            self.n = n
            self.diff_tree = Std.BinaryTree(self.n, lambda x, y: x + y)
            if array:
                for i in range(1, self.n + 1):
                    delta = array[i - 1] - (array[i - 2] if i > 1 else 0)
                    self.diff_tree.update(i, delta)

        def update_add(self, l, r, delta):
            """Update the values in the range [l, r] by adding delta"""
            self.diff_tree.update(l, delta)
            self.diff_tree.update(r + 1, -delta)

        def query_value(self, i):
            """Query the value at index i"""
            return self.diff_tree.query(i)

# ————————————————————— Division line ——————————————————————


class Solution:
    def minOperations(self, target: List[int], arr: List[int]) -> int:
        map_ = Counter()
        for i in range(len(target)):
            map_[target[i]] = i
        arr = [map_[num] for num in arr if num in map_]

        discretized_arr, mapping = Std.BinaryTree.discretize(arr)
        bit = Std.BinaryTree(n=len(discretized_arr), operation=Math.max, initial_value=0)

        for val in discretized_arr:
            max_val = bit.query(val - 1) + 1
            bit.update(val, max_val)
        return len(target) - bit.query(len(discretized_arr))


class Solution:
    def minOperations(self, target: List[int], arr: List[int]) -> int:
        map_ = Counter()
        for i in range(len(target)):
            map_[target[i]] = i
        arr = [map_[num] for num in arr if num in map_]

        lis = []
        for x in arr:
            pos = Std.bisect.bisect_left(lis, x)
            if pos == len(lis):
                lis.append(x)
            else:
                lis[pos] = x

        return len(target) - len(lis)
