'''
Author: NEFU AB-IN
Date: 2024-08-07 15:26:32
FilePath: \LeetCode\3241\3241.py
LastEditTime: 2024-08-07 15:41:28
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
    def timeTaken(self, edges: List[List[int]]) -> List[int]:
        n = len(edges) + 1
        g = Arr.graph(n)
        for x, y in edges:
            g[x].append(y)
            g[y].append(x)

        def weight(x): return 2 if x % 2 == 0 else 1

        # nodes[x] 保存子树 x 的最大深度 max_d，次大深度 max_d2，以及最大深度要往儿子 my 走
        nodes = Arr.array(None, n)

        def dfs(x: int, fa: int) -> int:
            max_d = max_d2 = my = 0
            for y in g[x]:
                if y == fa:
                    continue
                depth = dfs(y, x) + weight(y)  # 从 x 出发，往 my 方向的最大深度
                if depth > max_d:
                    max_d2 = max_d
                    max_d = depth
                    my = y
                elif depth > max_d2:
                    max_d2 = depth
            nodes[x] = (max_d, max_d2, my)
            return max_d
        dfs(0, -1)

        ans = [0] * len(g)

        def reroot(x: int, fa: int, from_up: int) -> None:
            max_d, max_d2, my = nodes[x]
            ans[x] = max(from_up, max_d)
            w = weight(x)  # 从 y 到 x 的边权
            for y in g[x]:
                if y != fa:
                    up1 = from_up + w
                    up2 = (max_d2 if y == my else max_d) + w
                    reroot(y, x, Math.max(up1, up2))
        reroot(0, -1, 0)
        return ans
