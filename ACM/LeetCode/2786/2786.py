'''
Author: NEFU AB-IN
Date: 2024-06-27 11:23:00
FilePath: \LeetCode\2786\2786.py
LastEditTime: 2024-07-01 17:25:44
'''
# import
from functools import cache
from sys import setrecursionlimit, stdin, stdout, exit
from collections import Counter, deque, defaultdict
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from bisect import bisect_left, bisect_right
from datetime import datetime, timedelta
from string import ascii_lowercase, ascii_uppercase
from math import log, gcd, sqrt, fabs, ceil, floor
from typing import TypeVar, List, Dict, Any, Union, Generic

TYPE = TypeVar('TYPE')

# Data structure


class SA(Generic[TYPE]):
    def __init__(self, x: TYPE, y: TYPE):
        self.x: TYPE = x
        self.y: TYPE = y

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
def read_list(): return list(map(int, input().split()))

# Func


class std:
    letter_to_num = staticmethod(lambda x: ord(x.upper()) - 65)  # A -> 0
    num_to_letter = staticmethod(lambda x: ascii_uppercase[x])  # 0 -> A
    array = staticmethod(lambda x=0, size=N: [x] * size)
    array2d = staticmethod(lambda x=0, rows=N, cols=M: [std.array(x, cols) for _ in range(rows)])
    max = staticmethod(lambda a, b: a if a > b else b)
    min = staticmethod(lambda a, b: a if a < b else b)
    filter = staticmethod(lambda func, iterable: list(filter(func, iterable)))

    @staticmethod
    def find(container: Union[List[TYPE], str], value: TYPE) -> int:
        """Returns the index of value in container or -1 if value is not found."""
        if isinstance(container, list):
            try:
                return container.index(value)
            except ValueError:
                return -1
        elif isinstance(container, str):
            return container.find(value)

# —————————————————————Division line ——————————————————————


class Solution:
    def maxScore(self, nums: List[int], x: int) -> int:
        n = len(nums)
        dp = std.array(-INF, n)

        dp[0] = nums[0]
        res = nums[0]
        if nums[0] % 2 == 0:
            even_mx, odd_mx = nums[0], -INF
        else:
            even_mx, odd_mx = -INF, nums[0]

        for i in range(1, n):
            if nums[i] % 2 == 0:
                dp[i] = std.max(dp[i], even_mx + nums[i])
                dp[i] = std.max(dp[i], odd_mx + nums[i] - x)
                even_mx = std.max(even_mx, dp[i])
            if nums[i] % 2 != 0:
                dp[i] = std.max(dp[i], odd_mx + nums[i])
                dp[i] = std.max(dp[i], even_mx + nums[i] - x)
                odd_mx = std.max(odd_mx, dp[i])

            res = std.max(res, dp[i])

        return res


# print(Solution().maxScore([2, 1, 3, 7, 9], 50))
print(Solution().maxScore([85, 12], 79))
