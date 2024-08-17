'''
Author: NEFU AB-IN
Date: 2024-08-13 16:44:07
FilePath: \LeetCode\902\902.py
LastEditTime: 2024-08-13 17:00:07
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
    def atMostNGivenDigitSet(self, digits: List[str], n: int) -> int:
        s = str(n)
        digits = list(map(int, digits))

        @lru_cache(None)
        def dfs(i, is_limit, is_num):
            if i == len(s):
                return int(is_num)
            res = 0
            if not is_num:
                res = dfs(i + 1, False, False)

            up = int(s[i]) if is_limit else 9
            down = 0 if is_num else 1

            for d in digits:
                if down <= d <= up:
                    res += dfs(i + 1, is_limit and up == d, True)

            return res

        return dfs(0, True, False)


Solution().atMostNGivenDigitSet(["1", "3", "5", "7"], 11)
