'''
Author: NEFU AB-IN
Date: 2024-07-21 20:17:29
FilePath: \LeetCode\1186\1186.py
LastEditTime: 2024-07-21 21:13:05
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

# ————————————————————— Division line ——————————————————————


class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        n = len(arr)
        arr = [0, *arr]
        max_, sum_, min_ = -INF, 0, INF

        for i in range(1, n + 1):
            sum_ += arr[i]
            max_ = Math.max(max_, arr[i])
            min_ = Math.min(min_, arr[i])

        if min_ > 0:
            return sum_
        if max_ < 0:
            return max_

        dpl, dpr = Arr.array(0, n + 2), Arr.array(0, n + 2)
        for i in range(1, n + 1):
            dpl[i] = Math.max(arr[i], dpl[i - 1] + arr[i])
        for i in range(n, -1, -1):
            dpr[i] = Math.max(arr[i], dpr[i + 1] + arr[i])

        for i in range(1, n + 1):
            max_ = max(max_, dpl[i - 1] + dpr[i + 1], dpl[i - 1], dpr[i + 1])
        return max_


arr = IO.read_list()
print(Solution().maximumSum(arr))
