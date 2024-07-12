'''
Author: NEFU AB-IN
Date: 2024-07-08 11:20:41
FilePath: \LeetCode\724\724.py
LastEditTime: 2024-07-08 17:06:41
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
from typing import Any, Dict, Generic, List, Tuple, TypeVar, Union

# Constants
TYPE = TypeVar('TYPE')
N = int(2e5 + 10)  # If using AR, modify accordingly
M = int(20)  # If using AR, modify accordingly
INF = int(2e9)
OFFSET = int(100)

# Set recursion limit
setrecursionlimit(INF)

class Arr:
    array = staticmethod(lambda x=0, size=N: [x] * size)
    array2d = staticmethod(lambda x=0, rows=N, cols=M: [Arr.array(x, cols) for _ in range(rows)])
    graph = staticmethod(lambda size=N: [[] for _ in range(size)])
    @staticmethod
    def to_1_indexed(data: Union[List, str, List[List]]):
        """Adds a zero prefix to the data and returns the modified data and its length."""
        if isinstance(data, list):
            if all(isinstance(item, list) for item in data):  # Check if it's a 2D array
                new_data = [[0] * (len(data[0]) + 1)] + [[0] + row for row in data]
                return new_data, len(new_data) - 1, len(new_data[0]) - 1
            else:
                new_data = [0] + data
                return new_data, len(new_data) - 1
        elif isinstance(data, str):
            new_data = '0' + data
            return new_data, len(new_data) - 1
        else:
            raise TypeError("Input must be a list, a 2D list, or a string")

class Str:
    letter_to_num = staticmethod(lambda x: ord(x.upper()) - 65)  # A -> 0
    num_to_letter = staticmethod(lambda x: ascii_uppercase[x])  # 0 -> A
    removeprefix = staticmethod(lambda s, prefix: s[len(prefix):] if s.startswith(prefix) else s)
    removesuffix = staticmethod(lambda s, suffix: s[:-len(suffix)] if s.endswith(suffix) else s)

class Math:
    max = staticmethod(lambda a, b: a if a > b else b)
    min = staticmethod(lambda a, b: a if a < b else b)

class IO:
    input = staticmethod(lambda: stdin.readline().rstrip("\r\n"))
    read = staticmethod(lambda: map(int, IO.input().split()))
    read_list = staticmethod(lambda: list(IO.read()))


class Std:
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
    
    class SparseTable:
        def __init__(self, data: list, func=lambda x, y: x | y):
            self.func = func
            self.st = [list(data)]
            i, n = 1, len(self.st[0])
            while 2 * i <= n:
                pre = self.st[-1]
                self.st.append([func(pre[j], pre[j + i]) for j in range(n - 2 * i + 1)])
                i <<= 1
            # st[i][j] 表示从索引 j 开始，长度为 2^i 的区间的统计值
            # 如 st[2][0] = min(st[1][0], st[1][2])：这里 st[1][0] 和 st[1][2] 分别表示从第 0 位开始长度为 2 的区间 [0, 1] 和从第 2 位开始长度为 2 的区间 [2, 3] 的最小值。因此，st[2][0] 表示从第 0 位开始长度为 4 的区间 [0, 3] 的最小值。

        def query(self, begin: int, end: int):  # 查询闭区间[begin, end]
            lg = (end - begin + 1).bit_length() - 1
            return self.func(self.st[lg][begin], self.st[lg][end - (1 << lg) + 1])



# ————————————————————— Division line ——————————————————————
class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        
        n = len(nums)
        nums = [0] + nums
        pre = Arr.array(0, len(nums))
        
        for i in range(1, n + 1):
            pre[i] = pre[i - 1] + nums[i]
        
        for i in range(1, n + 1):
            if pre[i] - pre[0] == pre[n] - pre[i - 1]:
                return i - 1
        
        return -1
    