'''
Author: NEFU AB-IN
Date: 2024-07-05 19:59:10
FilePath: \LeetCode\3086\3086.1.py
LastEditTime: 2024-07-05 20:31:44
'''
# import
from bisect import bisect_left, bisect_right
from collections import Counter, defaultdict, deque
from datetime import datetime, timedelta
from functools import cache
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from math import ceil, fabs, floor, gcd, log, sqrt
from string import ascii_lowercase, ascii_uppercase
from sys import exit, setrecursionlimit, stdin, stdout
from typing import Any, Dict, Generic, List, TypeVar, Union

TYPE = TypeVar('TYPE')

# Data structure


class SA(Generic[TYPE]):
    def __init__(self, x: TYPE, y: TYPE):
        self.x: TYPE = x
        self.y: TYPE = y

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
def read_list(): return list(map(int, input().split()))

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
class Solution:
    def minimumMoves(self, nums: List[int], k: int, maxChanges: int) -> int:
        index_1_set = [2] * maxChanges
        for i, num in enumerate(nums):
            if num == 1: index_1_set.append(i) 
        
        index_1_set.sort()
        
        def check(index: int):
            tmp_lst = []
            for index_1 in index_1_set:
                tmp_lst.append(abs(index_1 - index))
            
            tmp_lst.sort()
            return sum(tmp_lst[:k]) < 
                
        
        l, r = 0, len(nums) - 1
        while l < r:
            mid = (l + r) >> 1
            if check(mid):
                r = mid
            else:
                l = mid + 1
