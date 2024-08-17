'''
Author: NEFU AB-IN
Date: 2024-08-14 12:07:29
FilePath: \LeetCode\3152\3152.py
LastEditTime: 2024-08-14 13:04:20
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
    class Func:
        @staticmethod
        def find(container: Union[List[TYPE], str], value: TYPE):
            """Returns the index of value in container or -1 if value is not found."""
            if isinstance(container, list):
                try:
                    return container.index(value)
                except ValueError:
                    return -1
            elif isinstance(container, str):
                return container.find(value)  # type: ignore

        @staticmethod
        def pairwise(iterable):
            """Return successive overlapping pairs taken from the input iterable."""
            a, b = tee(iterable)
            next(b, None)
            return zip(a, b)

    class PrefixSum:
        def __init__(self, nums: List[int]):
            """Initializes the PrefixSum object with the given list of numbers.

            Args:
                nums (List[int]): The input array of integers (0-based index).
            """
            self.n = len(nums)
            self.prefix_sum = Arr.array(0, self.n + 1)  # 1-based index

            # Compute the prefix sum with adjusted indexing
            for i in range(1, self.n + 1):
                # Adjust nums index by subtracting 1 to map 1-based prefix_sum to 0-based nums
                self.prefix_sum[i] = self.prefix_sum[i - 1] + nums[i - 1]

        def query(self, left: int, right: int) -> int:
            """Returns the sum of elements in the range [left, right].
            the input coordinates is 0-based indexing.

            Returns:
                int: The sum of elements between the indices `left` and `right`.
            """
            # Convert the 0-based indices to 1-based by adding 1
            return self.prefix_sum[right + 1] - self.prefix_sum[left]

# ————————————————————— Division line ——————————————————————


class Solution:
    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        pre = []
        for x, y in Std.Func.pairwise(nums):
            pre.append(int(x & 1 == y & 1))

        pre_ = Std.PrefixSum(pre)
        ans = []
        for l, r in queries:
            ans.append(pre_.query(l, r - 1))

        return ans
