'''
Author: NEFU AB-IN
Date: 2024-08-13 22:32:27
FilePath: \CF\966\d\d.py
LastEditTime: 2024-08-13 23:39:31
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


def solve():
    n, = IO.read()
    a = [0] + IO.read_list()
    s = " " + IO.input()

    pre = Arr.array(0, n + 2)
    for i in range(1, n + 1):
        pre[i] = pre[i - 1] + a[i]

    ans = 0
    l, r = 1, len(s) - 1
    while l < len(s) and r >= 0 and l < r:
        while l < len(s):
            if s[l] == 'L':
                break
            l += 1

        while r >= 0:
            if s[r] == 'R':
                break
            r -= 1

        if l < r:
            ans += pre[r] - pre[l - 1]
            l += 1
            r -= 1
    print(ans)


T, = IO.read()

for _ in range(T):
    solve()
