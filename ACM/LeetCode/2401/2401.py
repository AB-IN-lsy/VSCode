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
    pass


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
    def __or__(self, other): return Bit(super(Bit, self).__or__(other))
    def __and__(self, other): return Bit(super(Bit, self).__and__(other))
    def __sub__(self, other): return Bit(super(Bit, self).__and__(~other))

    all_ones_mask = staticmethod(lambda length: (1 << length) - 1)
    all_zeros_mask = staticmethod(lambda length: 0)
    single_bit_mask = staticmethod(lambda position: 1 << position)
    range_mask = staticmethod(lambda start, end: ((1 << (end - start + 1)) - 1) << start)

# ————————————————————— Division line ——————————————————————


class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        l, ans, or_ = 0, 1, Bit(0)
        for r, num in enumerate(nums):
            bit_num = Bit(num)
            while or_ & bit_num:
                or_ -= Bit(nums[l])
                l += 1
            or_ |= Bit(num)
            ans = Math.max(ans, r - l + 1)
        return ans
