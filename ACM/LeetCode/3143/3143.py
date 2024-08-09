'''
Author: NEFU AB-IN
Date: 2024-08-03 19:53:48
FilePath: \LeetCode\3143\3143.py
LastEditTime: 2024-08-03 21:21:34
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
    def maxPointsInsideSquare(self, points: List[List[int]], s: str) -> int:
        dict_ = defaultdict(lambda: {"string": set(), "cnt": 0})

        remove_ = set()
        for point, c in zip(points, s):
            value = Math.max(abs(point[0]), abs(point[1]))
            if value in remove_:
                continue
            if c in dict_[value]["string"]:
                del dict_[value]
                remove_.add(value)
                continue
            dict_[value]["string"].add(c)
            dict_[value]["cnt"] += 1

        max_ = max(remove_) if remove_ else INF
        set_ = set()
        ans = 0
        for _, value in sorted(dict_.items()):
            if _ > max_:
                return ans
            len_ = len(set_)
            set_.update(value["string"])
            if len(set_) != len_ + len(value["string"]):
                return ans
            else:
                ans += value["cnt"]
        return ans


print(Solution().maxPointsInsideSquare([[1, 1], [-1, -1], [2, -2]], "ccd"))
