'''
Author: NEFU AB-IN
Date: 2024-07-23 16:18:08
FilePath: \LeetCode\1674\1674.py
LastEditTime: 2024-07-23 16:40:21
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
    pass

# ————————————————————— Division line ——————————————————————


class Solution:
    def minMoves(self, nums: List[int], limit: int) -> int:
        n = len(nums)
        dis = Arr.array(2 * limit + 3)
        for i in range(n // 2):
            a = Math.min(nums[i], nums[n - i - 1])
            b = Math.max(nums[i], nums[n - i - 1])

            # 1. target ∈ [2, a+1)，需要操作两次
            dis[2] += 2
            dis[a + 1] -= 2

            # 2. target ∈ [a+1, a+b)，需要操作一次
            dis[a + 1] += 1
            dis[a + b] -= 1

            # 3. target ∈ (a+b, b + limit]，需要操作一次
            dis[a + b + 1] += 1
            dis[b + limit + 1] -= 1

            # 4. target ∈ (b+limit, 2*limit]，需要操作两次
            dis[b + limit + 1] += 2
            dis[2 * limit + 1] -= 2

        sum_ = 0
        res = INF
        for i in range(2, len(dis)):
            sum_ += dis[i]
            res = Math.min(res, sum_)
        return res
