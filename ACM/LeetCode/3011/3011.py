'''
Author: NEFU AB-IN
Date: 2024-07-13 19:17:41
FilePath: \LeetCode\3011\3011.py
LastEditTime: 2024-07-13 23:27:44
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


class Bit:
    def __init__(self, value: int):
        self.value = value
        self.bin_rep = bin(value)[2:]

    def bit_length(self): return len(self.bin_rep)
    def bit_count(self): return self.bin_rep.count('1')
    def lowest1(self): return self.value & -self.value
    def lowest0(self): return ~self.value & (self.value + 1)
    def get_bits(self, start, end): return self.bin_rep[start:end + 1]
    def clear_lowest1(self): return self.value & (self.value - 1)
    def clear_lowest0(self): return self.value | (self.value + 1)

    def all_ones_mask(self, length): return (1 << length) - 1
    def all_zeros_mask(self, length): return 0
    def single_bit_mask(self, position): return 1 << position
    def range_mask(self, start, end): return ((1 << (end - start + 1)) - 1) << start


class Std:
    pass

# ————————————————————— Division line ——————————————————————


class Solution:
    def canSortArray(self, nums: List[int]) -> bool:
        n = len(nums)
        for _ in range(n):
            for i in range(1, n):
                if nums[i - 1] > nums[i]:
                    if Bit(nums[i - 1]).bit_count() != Bit(nums[i]).bit_count():
                        return False
                    nums[i - 1], nums[i] = nums[i], nums[i - 1]

        return True


print(Solution().canSortArray([8, 4, 2, 30, 15]))
