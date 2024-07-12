# import
from sys import setrecursionlimit, stdin, stdout, exit
from collections import Counter, deque, defaultdict
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from bisect import bisect_left, bisect_right
from datetime import datetime, timedelta
from string import ascii_lowercase, ascii_uppercase
from math import log, gcd, sqrt, fabs, ceil, floor
from types import GeneratorType
from typing import TypeVar, List, Dict, Any, Callable, Union
T = TypeVar('T')


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

    # Recursion
    @staticmethod
    def bootstrap(f, stack=None):
        if stack is None:
            stack = []

        def wrappedfunc(*args, **kwargs):
            if stack:
                return f(*args, **kwargs)
            else:
                to = f(*args, **kwargs)
                while True:
                    if isinstance(to, GeneratorType):
                        stack.append(to)
                        to = next(to)
                    else:
                        stack.pop()
                        if not stack:
                            break
                        to = stack[-1].send(to)
                return to

        return wrappedfunc

    letter_to_num = staticmethod(lambda x: ord(x.upper()) - 65)  # A -> 0
    num_to_letter = staticmethod(lambda x: ascii_uppercase[x])  # 0 -> A
    array = staticmethod(lambda x=0, size=N: [x] * size)
    array2d = staticmethod(
        lambda x=0, rows=N, cols=M: [std.array(x, cols) for _ in range(rows)])
    max = staticmethod(lambda a, b: a if a > b else b)
    min = staticmethod(lambda a, b: a if a < b else b)
    filter = staticmethod(lambda func, iterable: list(filter(func, iterable)))
    @staticmethod
    def find(container: Union[List[T], str], value: T) -> int:
        """Returns the index of value in container or -1 if value is not found."""
        if isinstance(container, list):
            try:
                return container.index(value)
            except ValueError:
                return -1
        elif isinstance(container, str):
            return container.find(value)

# —————————————————————Division line ——————————————————————
nums = read_list()
n = len(nums)
dp = std.array(1, n)

res = 0

for i in range(n):
    for j in range(i):
        if nums[i] <= nums[j]:
            dp[i] = max(dp[i], dp[j] + 1)
    res = max(res, dp[i])
print(res)


res = 0
nums = nums[::-1]
dp = std.array(1, n)
for i in range(n):
    for j in range(i):
        if nums[i] < nums[j]:
            dp[i] = max(dp[i], dp[j] + 1)
    res = max(res, dp[i])
print(res)
