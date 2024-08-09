'''
Author: NEFU AB-IN
Date: 2024-07-12 11:05:52
FilePath: \LeetCode\3180\3180.py
LastEditTime: 2024-07-12 15:16:57
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
N = int(2e5 + 10)  # If using AR, modify accordingly
M = int(20)  # If using AR, modify accordingly
INF = int(2e9)
OFFSET = int(100)
MOD = int(1e9 + 7)

# Set recursion limit
setrecursionlimit(INF)


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
    def maxTotalReward(self, rewardValues: List[int]) -> int:
        rewardValues.sort()
        rewardValues = [0] + rewardValues
        n = len(rewardValues) - 1
        m = rewardValues[-1] * 2  # 最大的可能是最大值*2

        dp = Arr.array2d(False, n + 1, m + 1, )
        dp[0][0] = True

        for i in range(1, n + 1):
            for j in range(m):
                v = rewardValues[i]
                dp[i][j] = dp[i - 1][j] or (dp[i - 1][j - v] and v < j < 2 * v)

        for j in range(m - 1, -1, -1):
            if dp[n][j]:
                return j
        return 0
