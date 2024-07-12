# 3.8.19 import
import random
from collections import Counter, defaultdict, deque
from datetime import datetime, timedelta
from functools import lru_cache
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from itertools import combinations, compress, permutations, starmap, tee
from math import ceil, fabs, floor, gcd, log, sqrt
from re import L
from string import ascii_lowercase, ascii_uppercase
from sys import exit, setrecursionlimit, stdin
from typing import Any, Dict, List, Tuple, TypeVar, Union

# Constants
TYPE = TypeVar('TYPE')
N = int(2e5 + 10)  # If using AR, modify accordingly
M = int(20)  # If using AR, modify accordingly
INF = int(2e9)
OFFSET = int(100)

# Set recursion limit
setrecursionlimit(INF)


class Arr:
    array = staticmethod(lambda x=0, size=N: [x() if callable(x) else x for _ in range(size)])
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
    pass

# ————————————————————— Division line ——————————————————————


class Solution:
    def incremovableSubarrayCount(self, arr: List[int]) -> int:
        arr, n = Arr.to_1_indexed(arr)

        l = 1
        while l <= n and arr[l] > arr[l - 1]:
            l += 1
        # l = arr[4] = 5
        if l == n + 1:
            return n * (n + 1) // 2

        print(arr[l])
        r = n
        while r >= 1 and arr[r] > arr[r - 1]:
            r -= 1
        # r = arr[8] = 5
        ans = n - r + 2
        print(ans, arr[r])

        for i in range(1, l):
            while r <= n and arr[r] <= arr[i]:
                r += 1
            ans += n - r + 2

        return ans


# print(Solution().incremovableSubarrayCount([1, 2, 6, 5, 9, 3, 10, 5, 11, 12]))
print(Solution().incremovableSubarrayCount([8, 7, 6, 6]))
print(Solution().incremovableSubarrayCount([6, 5, 7, 8]))
