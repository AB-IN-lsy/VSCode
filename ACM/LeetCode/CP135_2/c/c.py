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
    def minChanges(self, nums: List[int], k: int) -> int:
        n = len(nums)
        cnt_ = Counter()
        for i in range(n // 2):
            left = nums[i]
            right = nums[n - i - 1]
            cnt_[abs(left - right)] += 1
        cnt_ = cnt_.most_common()
        set_ = {num[0] for num in cnt_}

        def canAchieveX(nums, k, changes):
            for X in set_:
                cnt = 0
                for i in range(n // 2):
                    left = nums[i]
                    right = nums[n - i - 1]
                    if abs(left - right) == X:
                        continue
                    if (left > k and right > k) or (Math.min(left, right) + X > k and Math.max(left, right) - X < 0):
                        cnt += 2
                    else:
                        cnt += 1
                    if cnt > changes:
                        break
                if cnt <= changes:
                    return True
            return False

        left, right = 0, len(nums)

        while left < right:
            mid = (left + right) // 2
            if canAchieveX(nums, k, mid):
                right = mid
            else:
                left = mid + 1

        return left


# print(Solution().minChanges([1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0], 1))
print(Solution().minChanges([1, 10, 5, 1, 4, 6, 4, 2, 4, 9, 7, 9, 0, 11], 12))
