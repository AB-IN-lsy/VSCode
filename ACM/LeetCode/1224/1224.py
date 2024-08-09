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
    def maxEqualFreq(self, nums: List[int]) -> int:
        freq = defaultdict(int)  # 每个数字的频率
        freqCount = defaultdict(int)  # 每个频率出现的次数
        maxFreq = 0  # 最大频率
        result = 0  # 最长前缀的长度

        for i, num in enumerate(nums):
            if freq[num] > 0:
                freqCount[freq[num]] -= 1

            freq[num] += 1
            freqCount[freq[num]] += 1

            maxFreq = max(maxFreq, freq[num])

            if (maxFreq == 1 or
                (freqCount[maxFreq] * maxFreq + freqCount[maxFreq - 1] * (maxFreq - 1) == i + 1 and freqCount[maxFreq] == 1) or
                    (freqCount[maxFreq] * maxFreq + 1 == i + 1 and freqCount[1] == 1)):
                result = i + 1

        return result
