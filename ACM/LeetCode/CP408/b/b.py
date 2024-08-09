'''
Author: NEFU AB-IN
Date: 2024-07-28 01:35:58
FilePath: \LeetCode\CP408\b\b.py
LastEditTime: 2024-07-28 10:38:28
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
    def nonSpecialCount(self, l: int, r: int) -> int:
        N = int(sqrt(r)) + 10
        st, primes = [0] * N, []

        def init():
            for i in range(2, N):
                if st[i] == 0:
                    primes.append(i)
                j = 0
                while primes[j] * i < N:
                    st[primes[j] * i] = 1
                    if i % primes[j] == 0:
                        break
                    j += 1
        init()
        set_ = set()
        for p in primes:
            pp = p * p
            if pp >= l and pp <= r:
                set_.add(pp)

        return r - l + 1 - len(set_)


Solution().nonSpecialCount(1, 4)
