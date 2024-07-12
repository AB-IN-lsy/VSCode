import random
from collections import Counter, defaultdict, deque
from datetime import datetime, timedelta
from enum import Enum
from functools import lru_cache
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from itertools import combinations, compress, permutations, starmap, tee
from math import ceil, fabs, floor, gcd, log, sqrt
from string import ascii_lowercase, ascii_uppercase
from sys import exit, setrecursionlimit, stdin
from typing import Any, Dict, List, Tuple, TypeVar, Union

# Constants
TYPE = TypeVar('TYPE')
N = int(2e5 + 10)  # If using AR, modify accordingly
M = int(20)  # If using AR, modify accordingly
INF = int(2e9)
OFFSET = int(100)

# Set recursion limit
setrecursionlimit(INF)

class Arr:
    array = staticmethod(lambda x=0, size=N: [x() if callable(x) else x for _ in range(size)])
    array2d = staticmethod(lambda x=0, rows=N, cols=M: [Arr.array(x, cols) for _ in range(rows)])
    graph = staticmethod(lambda size=N: [[] for _ in range(size)])
    @staticmethod
    def to_1_indexed(data: Union[List, str, List[List]]):
        """Adds a zero prefix to the data and returns the modified data and its length."""
        if isinstance(data, list):
            if all(isinstance(item, list) for item in data):  # Check if it's a 2D array
                new_data = [[0] * (len(data[0]) + 1)] + [[0] + row for row in data]
                return new_data, len(new_data) - 1, len(new_data[0]) - 1
            else:
                new_data = [0] + data
                return new_data, len(new_data) - 1
        elif isinstance(data, str):
            new_data = '0' + data
            return new_data, len(new_data) - 1
        else:
            raise TypeError("Input must be a list, a 2D list, or a string")

class Str:
    letter_to_num = staticmethod(lambda x: ord(x.upper()) - 65)  # A -> 0
    num_to_letter = staticmethod(lambda x: ascii_uppercase[x])  # 0 -> A
    removeprefix = staticmethod(lambda s, prefix: s[len(prefix):] if s.startswith(prefix) else s)
    removesuffix = staticmethod(lambda s, suffix: s[:-len(suffix)] if s.endswith(suffix) else s)

class Math:
    max = staticmethod(lambda a, b: a if a > b else b)
    min = staticmethod(lambda a, b: a if a < b else b)

class IO:
    input = staticmethod(lambda: stdin.readline().rstrip("\r\n"))
    read = staticmethod(lambda: map(int, IO.input().split()))
    read_list = staticmethod(lambda: list(IO.read()))

class Std:
    pass

# ————————————————————— Division line ——————————————————————




class Arr:
    array = staticmethod(lambda x=0, size=N: [x() if callable(x) else x for _ in range(size)])
    array2d = staticmethod(lambda x=0, rows=N, cols=N: [Arr.array(x, cols) for _ in range(rows)])
    graph = staticmethod(lambda size=N: [[] for _ in range(size)])

class SegmentTree:
    from enum import Enum

    class Mode(Enum):
        SUM = "sum"
        MAX = "max"
        MIN = "min"
        GCD = "gcd"
        MUL = "mul"
    
    class Node:
        def __init__(self, l: int = 0, r: int = 0):
            self.l = l
            self.r = r
            self.len = 0
            self.add_tag = 0
            self.mul_tag = 1
            self.gcd_val = 0
            self.max_val = -INF
            self.min_val = INF

    def __init__(self, n: int):
        self.n = n
        self.tr = Arr.array(lambda: SegmentTree.Node(0, 0), n << 2)
        self.mode_to_operation = {
            SegmentTree.Mode.MAX: Math.max,
            SegmentTree.Mode.MIN: Math.min,
            SegmentTree.Mode.GCD: gcd,
        }
    
    def ls(self, p: int) -> int:
        """Return left child index"""
        return p << 1
    
    def rs(self, p: int) -> int:
        """Return right child index"""
        return p << 1 | 1
    
    def pushup(self, p: int, mode: Mode):
        """Push up the values to the parent node based on the mode"""
        if mode == SegmentTree.Mode.SUM:
            self.tr[p].len = self.tr[self.ls(p)].len + self.tr[self.rs(p)].len
        elif mode in self.mode_to_operation:
            op = self.mode_to_operation[mode]
            if mode == SegmentTree.Mode.MAX:
                self.tr[p].max_val = op(self.tr[self.ls(p)].max_val, self.tr[self.rs(p)].max_val)
            elif mode == SegmentTree.Mode.MIN:
                self.tr[p].min_val = op(self.tr[self.ls(p)].min_val, self.tr[self.rs(p)].min_val)
            elif mode == SegmentTree.Mode.GCD:
                self.tr[p].gcd_val = op(self.tr[self.ls(p)].gcd_val, self.tr[self.rs(p)].gcd_val)
    
    def pushdown(self, p: int, mode: Mode):
        """Push down the tags to the children nodes"""
        if mode in {SegmentTree.Mode.SUM, SegmentTree.Mode.MUL}:
            if self.tr[p].add_tag != 0 or self.tr[p].mul_tag != 1:
                ls, rs = self.ls(p), self.rs(p)
                self.apply(p, ls, mode)
                self.apply(p, rs, mode)
                self.tr[p].add_tag = 0
                self.tr[p].mul_tag = 1
    
    def apply(self, p: int, child: int, mode: Mode):
        """Apply the tags to a child node"""
        if mode == SegmentTree.Mode.SUM:
            self.tr[child].len = self.tr[child].len * self.tr[p].mul_tag + self.tr[p].add_tag * (self.tr[child].r - self.tr[child].l + 1)
            self.tr[child].mul_tag *= self.tr[p].mul_tag
            self.tr[child].add_tag = self.tr[child].add_tag * self.tr[p].mul_tag + self.tr[p].add_tag
        elif mode == SegmentTree.Mode.MUL:
            self.tr[child].len *= self.tr[p].mul_tag
            self.tr[child].mul_tag *= self.tr[p].mul_tag
            self.tr[child].add_tag *= self.tr[p].mul_tag
    
    def build(self, p: int, l: int, r: int, mode: Mode, a: List[int] = None):
        """Build the segment tree based on the mode"""
        self.tr[p].l = l
        self.tr[p].r = r
        if l == r:
            if a:
                if mode in {SegmentTree.Mode.SUM, SegmentTree.Mode.MUL}:
                    self.tr[p].len = a[l]
                elif mode == SegmentTree.Mode.MAX:
                    self.tr[p].max_val = a[l]
                elif mode == SegmentTree.Mode.MIN:
                    self.tr[p].min_val = a[l]
                elif mode == SegmentTree.Mode.GCD:
                    self.tr[p].gcd_val = a[l]
            return
        mid = (l + r) >> 1
        self.build(self.ls(p), l, mid, mode, a)
        self.build(self.rs(p), mid + 1, r, mode, a)
        self.pushup(p, mode)
    
    def update_point(self, p: int, idx: int, value: int, mode: Mode):
        """Point update for the segment tree at index idx"""
        if self.tr[p].l == self.tr[p].r:
            if mode == SegmentTree.Mode.SUM or mode == SegmentTree.Mode.MUL:
                self.tr[p].len = value
            elif mode == SegmentTree.Mode.MAX:
                self.tr[p].max_val = value
            elif mode == SegmentTree.Mode.MIN:
                self.tr[p].min_val = value
            elif mode == SegmentTree.Mode.GCD:
                self.tr[p].gcd_val = value
            return
        
        mid = (self.tr[p].l + self.tr[p].r) >> 1
        if idx <= mid:
            self.update_point(self.ls(p), idx, value, mode)
        else:
            self.update_point(self.rs(p), idx, value, mode)
        self.pushup(p, mode)
    
    def update_range_add(self, p: int, l: int, r: int, d: int):
        """Range add update for the segment tree within the range [l, r]"""
        if l <= self.tr[p].l and self.tr[p].r <= r:
            self.tr[p].len += d * (self.tr[p].r - self.tr[p].l + 1)
            self.tr[p].add_tag += d
            return
        self.pushdown(p, SegmentTree.Mode.SUM)
        mid = (self.tr[p].l + self.tr[p].r) >> 1
        if l <= mid:
            self.update_range_add(self.ls(p), l, r, d)
        if mid < r:
            self.update_range_add(self.rs(p), l, r, d)
        self.pushup(p, SegmentTree.Mode.SUM)
    
    def update_range_mul(self, p: int, l: int, r: int, d: int):
        """Range multiply update for the segment tree within the range [l, r]"""
        if l <= self.tr[p].l and self.tr[p].r <= r:
            self.tr[p].len *= d
            self.tr[p].mul_tag *= d
            self.tr[p].add_tag *= d
            return
        self.pushdown(p, SegmentTree.Mode.MUL)
        mid = (self.tr[p].l + self.tr[p].r) >> 1
        if l <= mid:
            self.update_range_mul(self.ls(p), l, r, d)
        if mid < r:
            self.update_range_mul(self.rs(p), l, r, d)
        self.pushup(p, SegmentTree.Mode.MUL)
    
    def query(self, p: int, l: int, r: int, mode: Mode) -> int:
        """Query the segment tree within the range [l, r]"""
        if mode == SegmentTree.Mode.SUM: res = 0
        elif mode == SegmentTree.Mode.MAX: res = -INF
        elif mode == SegmentTree.Mode.MIN: res = INF
        elif mode == SegmentTree.Mode.GCD: res = 0
        
        if l <= self.tr[p].l and self.tr[p].r <= r:
            if mode == SegmentTree.Mode.SUM: return self.tr[p].len
            elif mode == SegmentTree.Mode.MAX: return self.tr[p].max_val
            elif mode == SegmentTree.Mode.MIN: return self.tr[p].min_val
            elif mode == SegmentTree.Mode.GCD: return self.tr[p].gcd_val

        self.pushdown(p, mode)
        mid = (self.tr[p].l + self.tr[p].r) >> 1
        if l <= mid:
            if mode == SegmentTree.Mode.SUM:
                res += self.query(self.ls(p), l, r, mode)
            else:
                op = self.mode_to_operation[mode]
                res = op(res, self.query(self.ls(p), l, r, mode))
        if r > mid:
            if mode == SegmentTree.Mode.SUM:
                res += self.query(self.rs(p), l, r, mode)
            else:
                op = self.mode_to_operation[mode]
                res = op(res, self.query(self.rs(p), l, r, mode))
        return res


# Constants for testing
N = 10
INF = int(2e9)

# Example usage with initial array
a = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
segment_tree = SegmentTree(len(a))

# Build segment trees based on the initial array
segment_tree.build(1, 0, len(a) - 1, SegmentTree.Mode.SUM, a)
segment_tree.build(1, 0, len(a) - 1, SegmentTree.Mode.MAX, a)
segment_tree.build(1, 0, len(a) - 1, SegmentTree.Mode.MIN, a)
segment_tree.build(1, 0, len(a) - 1, SegmentTree.Mode.GCD, a)

# Update and query operations
segment_tree.update_range_add(1, 1, 3, 5)  # Increment values in range [1, 3] by 5
segment_tree.update_range_mul(1, 2, 4, 2)  # Multiply values in range [2, 4] by 2
segment_tree.update_point(1, 5, 20, SegmentTree.Mode.MAX)  # Update value at index 5 to 20 for MAX mode
segment_tree.update_point(1, 6, 1, SegmentTree.Mode.MIN)  # Update value at index 6 to 1 for MIN mode

sum_result = segment_tree.query(1, 1, 3, SegmentTree.Mode.SUM)  # Query sum in range [1, 3]
max_result = segment_tree.query(1, 1, 6, SegmentTree.Mode.MAX)  # Query max in range [1, 3]
min_result = segment_tree.query(1, 1, 6, SegmentTree.Mode.MIN)  # Query min in range [1, 3]
gcd_result = segment_tree.query(1, 1, 6, SegmentTree.Mode.GCD)  # Query gcd in range [1, 3]

print(f"Sum result: {sum_result}")
print(f"Max result: {max_result}")
print(f"Min result: {min_result}")
print(f"GCD result: {gcd_result}")