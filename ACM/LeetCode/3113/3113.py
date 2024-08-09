'''
Author: NEFU AB-IN
Date: 2024-08-01 19:55:47
FilePath: \LeetCode\3113\3113.py
LastEditTime: 2024-08-01 20:49:33
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
    class SparseTable:
        def __init__(self, data: list, func=lambda x, y: x | y):
            """Initialize the Sparse Table with the given data and function."""
            self.func = func
            self.st = [list(data)]
            i, n = 1, len(self.st[0])
            while 2 * i <= n:
                pre = self.st[-1]
                self.st.append([func(pre[j], pre[j + i]) for j in range(n - 2 * i + 1)])
                i <<= 1

        def query(self, begin: int, end: int):
            """Query the combined result over the interval [begin, end]."""
            lg = (end - begin + 1).bit_length() - 1
            return self.func(self.st[lg][begin], self.st[lg][end - (1 << lg) + 1])

# ————————————————————— Division line ——————————————————————


class Solution:
    def numberOfSubarrays(self, nums: List[int]) -> int:
        st = Std.SparseTable(nums, Math.max)
        index_list_dict = defaultdict(list)
        res = 0
        for i, num in enumerate(nums):
            list_ = index_list_dict[num]
            if list_:
                pre_id = list_[-1]
                if st.query(pre_id, i) == num:
                    list_.append(i)
                else:
                    res += len(list_) * (len(list_) + 1) // 2
                    list_.clear()
                    list_.append(i)
            else:
                list_.append(i)

        for _, list_ in index_list_dict.items():
            res += len(list_) * (len(list_) + 1) // 2
        return res


print(Solution().numberOfSubarrays([1, 4, 3, 3, 2]))
