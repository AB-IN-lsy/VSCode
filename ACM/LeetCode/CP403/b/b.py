'''
Author: NEFU AB-IN
Date: 2024-06-23 11:07:58
FilePath: \LeetCode\CP403\b\b.py
LastEditTime: 2024-06-23 11:20:17
'''
# import
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
M = 20
INF = int(2e9)

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

    def minimumArea(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        x_max, y_max = 0, 0
        x_min, y_min = INF, INF
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    x_max = max(x_max, i)
                    y_max = max(y_max, j)
                    x_min = min(x_min, i)
                    y_min = min(y_min, j)

        return (x_max - x_min + 1) * (y_max - y_min + 1)
