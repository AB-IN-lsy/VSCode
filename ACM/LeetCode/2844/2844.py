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
    def minimumOperations(self, num: str) -> int:

        min_ = len(num) if '0' not in num else len(num) - num.count('0')
        num = num[::-1]

        strs = ["00", "52", "05", "57"]

        for str_ in strs:
            tmp = 0
            id_1 = num.find(str_[0])
            if id_1 == -1:
                continue
            tmp = id_1
            id_2 = num.find(str_[1], id_1 + 1)
            if id_2 == -1:
                continue
            tmp += id_2 - id_1 - 1
            min_ = Math.min(tmp, min_)
        return min_


Solution().minimumOperations("2245047")
