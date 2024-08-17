'''
Author: NEFU AB-IN
Date: 2024-08-11 10:33:01
FilePath: \LeetCode\CP410\d\d.py
LastEditTime: 2024-08-11 11:49:30
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
    pass

# ————————————————————— Division line ——————————————————————


class Solution:
    def countOfPairs(self, nums: List[int]) -> int:
        n = len(nums)
        max_ = max(nums)

        dp = Arr.array2d(0, n, max_ + 1)
        pre = Arr.array2d(0, n, max_ + 2)

        for j in range(nums[0] + 1):
            dp[0][j] = 1

        for j in range(max_ + 1):
            pre[0][j] = pre[0][j - 1] + dp[0][j] if j > 0 else dp[0][j]

        for i in range(1, n):
            for j in range(nums[i] + 1):
                dp[i][j] = pre[i - 1][j]
                if nums[i] - j < 0:
                    dp[i][j] -= pre[i - 1][nums[i] - j - 1]
                dp[i][j] %= MOD

            for j in range(max_ + 1):
                pre[i][j] = pre[i][j - 1] + dp[i][j] if j > 0 else dp[i][j]

        res = sum(dp[n - 1]) % MOD
        return res
