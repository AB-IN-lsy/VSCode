'''
Author: NEFU AB-IN
Date: 2024-08-15 23:21:56
FilePath: \Acwing\1022\1022.py
LastEditTime: 2024-08-15 23:22:02
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
import bisect


def dp(N, M, K, balls, blood):
    f = [[0] * (M + 1) for _ in range(N + 1)]
    for i in range(K):
        for j in range(N, balls[i] - 1, -1):
            for k in range(M, blood[i], - 1):
                f[j][k] = max(f[j][k], f[j - balls[i]][k - blood[i]] + 1)

    if f[N][M] == 0 : return 0, M

    return f[N][M], M - bisect.bisect_left(f[N], f[N][M]) + 1

N, M, K = map(int, stdin.readline().split())
balls, blood = [0] * K, [0] * K
for i in range(K):
    balls[i], blood[i] = map(int, stdin.readline().split())

C, R = dp(N, M, K, balls, blood)
print(str(C) + ' ' + str(R))
