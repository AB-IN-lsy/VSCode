'''
Author: NEFU AB-IN
Date: 2024-07-26 10:09:59
FilePath: \LeetCode\2740\2740.py
LastEditTime: 2024-07-26 10:11:15
'''
# 3.8.19 import
import random
from collections import Counter, defaultdict, deque
from datetime import datetime, timedelta
from functools import lru_cache
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from itertools import combinations, compress, permutations, starmap, tee
from math import ceil, comb, fabs, floor, gcd, hypot, log, perm, sqrt
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
                return container.find(value)
            
        @staticmethod
        def pairwise(iterable):
            """Return successive overlapping pairs taken from the input iterable."""
            a, b = tee(iterable)
            next(b, None)
            return zip(a, b)

# ————————————————————— Division line ——————————————————————
class Solution:
    def findValueOfPartition(self, nums: List[int]) -> int:
        return min(Math.max(y - x, 0) for x, y in Std.Func.pairwise(sorted(nums)))