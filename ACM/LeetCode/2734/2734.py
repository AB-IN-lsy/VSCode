'''
Author: NEFU AB-IN
Date: 2024-06-27 10:09:13
FilePath: \LeetCode\2734\2734.py
LastEditTime: 2024-06-27 11:14:32
'''
# import
from functools import cache
from sys import setrecursionlimit, stdin, stdout, exit
from collections import Counter, deque, defaultdict
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from bisect import bisect_left, bisect_right
from datetime import datetime, timedelta
from string import ascii_lowercase, ascii_uppercase
from math import log, gcd, sqrt, fabs, ceil, floor
from typing import TypeVar, List, Dict, Any, Callable, Union

TYPE = TypeVar('TYPE')

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
    letter_to_num = staticmethod(lambda x: ord(x.upper()) - 65)  # A -> 0
    num_to_letter = staticmethod(lambda x: ascii_uppercase[x])  # 0 -> A
    array = staticmethod(lambda x=0, size=N: [x] * size)
    array2d = staticmethod(
        lambda x=0, rows=N, cols=M: [std.array(x, cols) for _ in range(rows)])
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
    def smallestString(self, s: str) -> str:
        
        def change(s: List[str]):
            ss = []
            for i in s:
                ss.append(chr(ord(i) - 1))
            return ss
        
        nums = list(s)
        n = len(s)
        
        a_index_1 = std.find(nums, 'a')
        
        if 'a'* n == s:
            nums = ['a'] * (n - 1) + ['z']
        elif a_index_1 == 0:
            i, j = 1, 1
            while i < n and nums[i] == 'a':
                i += 1
            j = i
            while j < n and nums[j] != 'a':
                j += 1
            j -= 1
            nums[i : j + 1] = change(nums[i : j + 1])
        elif a_index_1 > 0:
            nums[: a_index_1] = change(nums[: a_index_1])
        else:
            nums = change(nums)
        
        return "".join(nums)
    
