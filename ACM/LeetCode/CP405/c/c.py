# 3.8.19 import
from bisect import bisect_left, bisect_right
from collections import Counter, defaultdict, deque
from datetime import datetime, timedelta
from functools import lru_cache
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from itertools import combinations, compress, permutations, starmap, tee
from math import ceil, fabs, floor, gcd, log, sqrt
from string import ascii_lowercase, ascii_uppercase
from sys import exit, setrecursionlimit, stdin, stdout
from typing import Any, Dict, Generic, List, TypeVar, Union

TYPE = TypeVar('TYPE')

# Data structure
class SA(Generic[TYPE]):
    def __init__(self, x: TYPE, y: TYPE):
        self.x = x
        self.y = y

    def __lt__(self, other: 'SA[TYPE]') -> bool:
        return self.x < other.x

    def __eq__(self, other: 'SA[TYPE]') -> bool:
        return self.x == other.x and self.y == other.y

    def __repr__(self) -> str:
        return f'SA(x={self.x}, y={self.y})'


# Constants
N = int(2e5 + 10)  # If using AR, modify accordingly
M = int(20)  # If using AR, modify accordingly
INF = int(2e9)
OFFSET = int(100)

# Set recursion limit
setrecursionlimit(INF)

# Read
def input(): return stdin.readline().rstrip("\r\n")  # Remove when Mutiple data
def read(): return map(int, input().split())
def read_list(): return list(read())


# Func
class std:
    letter_to_num = staticmethod(lambda x: ord(x.upper()) - 65)  # A -> 0
    num_to_letter = staticmethod(lambda x: ascii_uppercase[x])  # 0 -> A
    array = staticmethod(lambda x=0, size=N: [x] * size)
    array2d = staticmethod(lambda x=0, rows=N, cols=M: [std.array(x, cols) for _ in range(rows)])
    graph = staticmethod(lambda size=N: [[] for _ in range(size)])
    max = staticmethod(lambda a, b: a if a > b else b)
    min = staticmethod(lambda a, b: a if a < b else b)
    removeprefix = staticmethod(lambda s, prefix: s[len(prefix):] if s.startswith(prefix) else s)
    removesuffix = staticmethod(lambda s, suffix: s[:-len(suffix)] if s.endswith(suffix) else s)
    
    @staticmethod
    def find(container: Union[List[TYPE], str], value: TYPE):
        """Returns the index of value in container or -1 if value is not found."""
        if isinstance(container, list):
            try:
                return container.index(value)
            except ValueError:
                return -1
        elif isinstance(container, str):
            return container.find(value)
    @staticmethod
    def pairwise(iterable):
        """Return successive overlapping pairs taken from the input iterable."""
        a, b = tee(iterable)
        next(b, None)
        return zip(a, b)

# ————————————————————— Division line ——————————————————————
class Solution:
    def numberOfSubmatrices(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])

        
        
        prefix_X = std.array2d(0, m + 1, n + 1)
        prefix_Y = std.array2d(0, m + 1, n + 1)

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                prefix_X[i][j] = prefix_X[i - 1][j] + prefix_X[i][j - 1] - prefix_X[i - 1][j - 1] + (1 if grid[i - 1][j - 1] == 'X' else 0)
                prefix_Y[i][j] = prefix_Y[i - 1][j] + prefix_Y[i][j - 1] - prefix_Y[i - 1][j - 1] + (1 if grid[i - 1][j - 1] == 'Y' else 0)

        def count_XY(x1, y1, x2, y2):
            count_X = prefix_X[x2 + 1][y2 + 1] - prefix_X[x1][y2 + 1] - prefix_X[x2 + 1][y1] + prefix_X[x1][y1]
            count_Y = prefix_Y[x2 + 1][y2 + 1] - prefix_Y[x1][y2 + 1] - prefix_Y[x2 + 1][y1] + prefix_Y[x1][y1]
            return count_X, count_Y

        result = 0
        for x2 in range(m):
            for y2 in range(n):
                count_X, count_Y = count_XY(0, 0, x2, y2)
                if count_X > 0 and count_X == count_Y:
                    result += 1

        return result
    
Solution().numberOfSubmatrices([["X","X"],["X","Y"]])