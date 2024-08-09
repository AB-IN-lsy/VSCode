'''
Author: NEFU AB-IN
Date: 2024-07-27 09:40:49
FilePath: \LeetCode\3106\3106.py
LastEditTime: 2024-07-27 10:16:10
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


class Str:
    atoi = staticmethod(lambda x: ord(x.upper()) - 65)  # A -> 0
    itoa = staticmethod(lambda x: ascii_uppercase[x])   # 0 -> A
    removeprefix = staticmethod(lambda s, prefix: s[len(prefix):] if s.startswith(prefix) else s)
    removesuffix = staticmethod(lambda s, suffix: s[:-len(suffix)] if s.endswith(suffix) else s)


# ————————————————————— Division line ——————————————————————


class Solution:
    def getSmallestString(self, s: str, k: int) -> str:
        lst = list(s)
        for i, id_c in enumerate(map(Str.atoi, lst)):
            dis = Math.min(id_c - Str.atoi('a'), Str.atoi('z') - id_c + 1)
            if dis > k:
                lst[i] = Str.itoa(id_c - k).lower()
                break
            lst[i] = 'a'
            k -= dis
        return ''.join(lst)
