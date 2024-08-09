'''
Author: NEFU AB-IN
Date: 2024-07-28 01:35:58
FilePath: \LeetCode\CP408\c\c.py
LastEditTime: 2024-07-28 11:27:02
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
from sys import exit, prefix, setrecursionlimit, stdin
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


# ————————————————————— Division line ——————————————————————


class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        n = len(s)
        prefix_1 = Arr.array(0, n + 1)
        prefix_0 = Arr.array(0, n + 1)

        for i in range(1, n + 1):
            prefix_1[i] = prefix_1[i - 1] + (1 if s[i - 1] == '1' else 0)
            prefix_0[i] = prefix_0[i - 1] + (1 if s[i - 1] == '0' else 0)

        s = " " + s
        ans = 0

        def check(l, r):
            sum_1 = prefix_1[r] - prefix_1[l - 1]
            sum_0 = prefix_0[r] - prefix_0[l - 1]
            return sum_1 >= sum_0 ** 2

        for R in range(1, n + 1):
            l, r = 1, R
            while l < r:
                mid = l + r >> 1
                if check(mid, R):
                    r = mid
                else:
                    l = mid + 1
            if check(l, R):
                ans += R - l + 1
        return ans


Solution().numberOfSubstrings("101101")
