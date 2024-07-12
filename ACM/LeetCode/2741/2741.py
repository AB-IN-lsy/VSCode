'''
Author: NEFU AB-IN
Date: 2024-06-26 15:20:32
FilePath: \LeetCode\2741\2741.py
LastEditTime: 2024-06-26 22:16:13
'''
# import
from functools import cache
from sys import setrecursionlimit, stdin, stdout, exit
from collections import Counter, deque, defaultdict
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from bisect import bisect_left, bisect_right
from datetime import datetime, timedelta
from string import ascii_lowercase, ascii_uppercase
from math import log, gcd, sqrt, fabs, ceil, floor
from types import GeneratorType
from typing import TypeVar, List, Dict, Any, Callable


# Data structure
class SA:

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __lt__(self, other):
        return self.x < other.x


# Constants
N = int(2e5 + 10)  # If using AR, modify accordingly
M = int(20)  # If using AR, modify accordingly
INF = int(2e9)
E = int(100)

# Set recursion limit
setrecursionlimit(INF)

# Read
input = lambda: stdin.readline().rstrip("\r\n")  # Remove when Mutiple data
read = lambda: map(int, input().split())
read_list = lambda: list(map(int, input().split()))


# Func
class std:

    # Recursion
    @staticmethod
    def bootstrap(f, stack=None):
        if stack is None:
            stack = []

        def wrappedfunc(*args, **kwargs):
            if stack:
                return f(*args, **kwargs)
            else:
                to = f(*args, **kwargs)
                while True:
                    if isinstance(to, GeneratorType):
                        stack.append(to)
                        to = next(to)
                    else:
                        stack.pop()
                        if not stack:
                            break
                        to = stack[-1].send(to)
                return to

        return wrappedfunc

    letter_to_num = staticmethod(lambda x: ord(x.upper()) - 65)  # A -> 0
    num_to_letter = staticmethod(lambda x: ascii_uppercase[x])  # 0 -> A
    array = staticmethod(lambda x=0, size=N: [x] * size)
    array2d = staticmethod(
        lambda x=0, rows=N, cols=M: [std.array(x, cols) for _ in range(rows)])
    max = staticmethod(lambda a, b: a if a > b else b)
    min = staticmethod(lambda a, b: a if a < b else b)
    filter = staticmethod(lambda func, iterable: list(filter(func, iterable)))


# —————————————————————Division line ——————————————————————


class Solution:

    def specialPerm(self, nums: List[int]) -> int:
        n = len(nums)
        all_mask = (1 << n) - 1
        MOD = int(1e9 + 7)

        @cache
        def dp(mask, prev_index):
            if mask == all_mask:
                return 1

            total_perms = 0
            for i in range(n):
                if mask & (1 << i) == 0:
                    if prev_index == -1 or nums[prev_index] % nums[i] == 0 or nums[i] % nums[prev_index] == 0:
                        total_perms = (total_perms + dp(mask | (1 << i), i)) % MOD

            return total_perms

        return dp(0, -1)
    
    def specialPerm(self, nums: List[int]) -> int:
        MOD = int(1e9 + 7)
        n = len(nums)
        f = std.array2d(0, 1 << n, n)
        
        for i in range(n):
            f[1 << i][i] = 1
        
        for state in range(1, 1 << n):
            for i, x in enumerate(nums):
                if not state >> i & 1:
                    continue
                for j, y in enumerate(nums):
                    if i == j or not state >> j & 1:
                        continue
                    if x % y != 0 and y % x != 0:
                        continue
                    f[state][i] = (f[state][i] + f[state ^ (1 << i)][j]) % MOD
        
        return sum(f[(1 << n) - 1][i] for i in range(n)) % MOD

