'''
Author: NEFU AB-IN
Date: 2024-06-30 10:30:18
FilePath: \LeetCode\CP404\b\b.py
LastEditTime: 2024-07-01 20:39:53
'''
# 3.8.19 import
from bisect import bisect_left, bisect_right
from collections import Counter, defaultdict, deque
from datetime import datetime, timedelta
from functools import lru_cache
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from itertools import combinations, compress, permutations, starmap, tee
from math import ceil, fabs, floor, gcd, log, sqrt
from string import ascii_lowercase, ascii_uppercase
from sys import exit, setrecursionlimit, stdin, stdout
from typing import Any, Dict, Generic, List, TypeVar, Union

TYPE = TypeVar('TYPE')

# Data structure
class SA(Generic[TYPE]):
    def __init__(self, x: TYPE, y: TYPE):
        self.x = x
        self.y = y

    def __lt__(self, other: 'SA[TYPE]') -> bool:
        return self.x < other.x

    def __eq__(self, other: 'SA[TYPE]') -> bool:
        return self.x == other.x and self.y == other.y

    def __repr__(self) -> str:
        return f'SA(x={self.x}, y={self.y})'


# Constants
N = int(2e5 + 10)  # If using AR, modify accordingly
M = int(20)  # If using AR, modify accordingly
INF = int(2e9)
OFFSET = int(100)

# Set recursion limit
setrecursionlimit(INF)

# Read
def input(): return stdin.readline().rstrip("\r\n")  # Remove when Mutiple data
def read(): return map(int, input().split())
def read_list(): return list(read())


# Func
class std:
    letter_to_num = staticmethod(lambda x: ord(x.upper()) - 65)  # A -> 0
    num_to_letter = staticmethod(lambda x: ascii_uppercase[x])  # 0 -> A
    array = staticmethod(lambda x=0, size=N: [x] * size)
    array2d = staticmethod(lambda x=0, rows=N, cols=M: [std.array(x, cols) for _ in range(rows)])
    max = staticmethod(lambda a, b: a if a > b else b)
    min = staticmethod(lambda a, b: a if a < b else b)
    removeprefix = staticmethod(lambda s, prefix: s[len(prefix):] if s.startswith(prefix) else s)
    removesuffix = staticmethod(lambda s, suffix: s[:-len(suffix)] if s.endswith(suffix) else s)
    
    @staticmethod
    def find(container: Union[List[TYPE], str], value: TYPE):
        """Returns the index of value in container or -1 if value is not found."""
        if isinstance(container, list):
            try:
                return container.index(value)
            except ValueError:
                return -1
        elif isinstance(container, str):
            return container.find(value)
    @staticmethod
    def pairwise(iterable):
        """Return successive overlapping pairs taken from the input iterable."""
        a, b = tee(iterable)
        next(b, None)
        return zip(a, b)

# ————————————————————— Division line ——————————————————————


class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        return max(
            odd := sum(x & 1 for x in nums),
            len(nums) - odd,
            1 + sum((x & 1) ^ (y & 1) for x, y in std.pairwise(nums))
        )

    def maximumLength(self, nums: List[int]) -> int:
        @lru_cache(None)
        def dfs(index, expected_parity, original_parity):
            # 递归终止条件：如果索引达到数组末尾，返回0
            if index == len(nums):
                return 0

            # 当前元素奇偶性符合预期
            if nums[index] % 2 == expected_parity:
                # 将当前元素加入子序列，并继续递归下一个元素
                # 更新expected_parity为(original_parity - expected_parity) % 2
                return 1 + dfs(index + 1, (original_parity - expected_parity) % 2, original_parity)
            else:
                # 当前元素不符合预期，不加入子序列，继续递归下一个元素
                return dfs(index + 1, expected_parity, original_parity)

        # 考虑所有可能的初始状态
        return max(dfs(0, 0, 1), dfs(0, 0, 0), dfs(0, 1, 0), dfs(0, 1, 1))
