'''
Author: NEFU AB-IN
Date: 2024-06-23 21:54:23
FilePath: \Acwing\1014\1014.py
LastEditTime: 2024-06-23 21:58:25
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
n, = read()
a = read_list()

def dp_func(a):
    dp = std.array(1, n)

    for i in range(1, n):
        for j in range(i):
            if a[j] < a[i]:
                dp[i] = std.max(dp[i], dp[j] + 1)
    return dp

dp1 = dp_func(a)
dp2 = dp_func(a[::-1])

res = 0
for i in range(n):
    res = max(res, dp1[i] + dp2[n - i - 1] - 1)
print(res)

