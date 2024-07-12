# import
from re import T
from sys import setrecursionlimit, stdin, stdout, exit
from collections import Counter, deque, defaultdict
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from bisect import bisect_left, bisect_right
from datetime import datetime, timedelta
from string import ascii_lowercase, ascii_uppercase
from math import log, gcd, sqrt, fabs, ceil, floor
from typing import TypeVar, List, Dict, Any, Union, Generic

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
input = lambda: stdin.readline().rstrip("\r\n")  # Remove when Mutiple data
read = lambda: map(int, input().split())
read_list = lambda: list(map(int, input().split()))


# Func
class std:
    letter_to_num = staticmethod(lambda x: ord(x.upper()) - 65)  # A -> 0
    num_to_letter = staticmethod(lambda x: ascii_uppercase[x])  # 0 -> A
    array = staticmethod(lambda x=0, size=N: [x] * size)
    array2d = staticmethod(lambda x=0, rows=N, cols=M: [std.array(x, cols) for _ in range(rows)])
    max = staticmethod(lambda a, b: a if a > b else b)
    min = staticmethod(lambda a, b: a if a < b else b)
    filter = staticmethod(lambda func, iterable: list(filter(func, iterable)))
    @staticmethod
    def find(container: Union[List[TYPE], str], value: TYPE) -> int:
        """Returns the index of value in container or -1 if value is not found."""
        if isinstance(container, list):
            try:
                return container.index(value)
            except ValueError:
                return -1
        elif isinstance(container, str):
            return container.find(value)

# —————————————————————Division line ——————————————————————

def min_defense_systems(n, heights):
    global res
    res = n
    
    up = std.array(0, n)
    down = std.array(0, n)
    
    def dfs(u, su, sd):
        global res
        
        # 剪枝
        if su + sd >= res:
            return 
        if u == n:
            res = min(res, su + sd)
            return 

        for i in range(su):
            if up[i] < heights[u]:
                tmp = up[i]
                up[i] = heights[u]
                dfs(u + 1, su, sd)
                up[i] = tmp
                break
        else:
            up[su] = heights[u]
            dfs(u + 1, su + 1, sd)
            
        for i in range(sd):
            if down[i] > heights[u]:
                tmp = down[i]
                down[i] = heights[u]
                dfs(u + 1, su, sd)
                down[i] = tmp
                break
        else:
            down[sd] = heights[u]
            dfs(u + 1, su, sd + 1)
    
    dfs(0, 0, 0)
    return res 

while True:
    n, = read()
    if n == 0:
        break
    
    heights = read_list()
    
    print(min_defense_systems(n, heights))