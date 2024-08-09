'''
Author: NEFU AB-IN
Date: 2024-08-01 10:23:14
FilePath: \LeetCode\lcp_40\lcp_40.py
LastEditTime: 2024-08-01 12:27:41
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
    def maxmiumScore(self, cards: List[int], cnt: int) -> int:
        max_ = 0
        heap_odd, heap_even = [], []
        for card in cards:
            if card & 1:
                heap_odd.append(card)
            else:
                heap_even.append((card, 1))

        heap_odd.sort()
        while len(heap_odd) > 1:
            x, y = heap_odd.pop(), heap_odd.pop()
            heap_even.append((x + y, 2))

        heap_even.sort(key=lambda x: x[0] / x[1], reverse=True)

        max_value = 0
        current_weight = 0

        for value, weight in heap_even:
            if weight == 1 and current_weight < cnt:
                max_value += value
                current_weight += 1
            elif weight == 2 and current_weight + 1 < cnt:
                max_value += value
                current_weight += 2

        return max_value if current_weight == cnt else 0


print(Solution().maxmiumScore([9, 5, 9, 1, 6, 10, 3, 4, 5, 1], 2))
