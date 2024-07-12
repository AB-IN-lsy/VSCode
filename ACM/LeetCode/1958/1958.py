'''
Author: NEFU AB-IN
Date: 2024-07-07 16:18:11
FilePath: \LeetCode\1958\1958.py
LastEditTime: 2024-07-07 17:37:42
'''
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
    def checkMove(self, board: List[List[str]], rMove: int, cMove: int, color: str) -> bool:
        # 判断每个方向是否存在以操作位置为起点的好线段
        def check(dx: int, dy: int) -> bool:
            x, y = rMove + dx, cMove + dy
            step = 1   # 当前遍历到的节点序号
            while 0 <= x < 8 and 0 <= y < 8:
                if step == 1:
                    # 第一个点必须为相反颜色
                    if board[x][y] == "." or board[x][y] == color:
                        return False
                else:
                    # 好线段中不应存在空格子
                    if board[x][y] == ".":
                        return False
                    # 遍历到好线段的终点，返回 true
                    if board[x][y] == color:
                        return True
                step += 1
                x += dx
                y += dy
            # 不存在符合要求的好线段
            return False
        
        # 从 x 轴正方向开始逆时针枚举 8 个方向
        dx = [1, 1, 0, -1, -1, -1, 0, 1]   # 行改变量
        dy = [0, 1, 1, 1, 0, -1, -1, -1]   # 列改变量
        for k in range(8):
            if check(dx[k], dy[k]):
                return True
        return False
