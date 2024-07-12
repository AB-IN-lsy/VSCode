'''
Author: NEFU AB-IN
Date: 2024-06-23 18:05:20
FilePath: \Acwing\275\275.py
LastEditTime: 2024-06-23 18:14:01
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
n, m = read()
w = std.array2d(0, n + E, m + E)
f = [std.array2d(0, n + E, M + E) for _ in range(n + m + E)]

for i in range(1, n + 1):
    w[i][1:] = read_list()

for k in range(2, n + m + 1):
    for i1 in range(1, n + 1):
        for i2 in range(1, n + 1):
            j1 = k - i1
            j2 = k - i2
            if 1 <= j1 <= m and 1 <= j2 <= m:
                t = w[i1][j1]
                if i1 != i2:
                    t += w[i2][j2]
                f[k][i1][i2] = max(f[k][i1][i2], f[k - 1][i1 - 1][i2 - 1] + t,
                                   f[k - 1][i1 - 1][i2] + t,
                                   f[k - 1][i1][i2 - 1] + t,
                                   f[k - 1][i1][i2] + t)

print(f[n + m][n][n])
