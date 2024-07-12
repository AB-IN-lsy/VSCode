# import
from sys import setrecursionlimit, stdin, stdout, exit
from collections import Counter, deque, defaultdict
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from bisect import bisect_left, bisect_right
from datetime import datetime, timedelta
from string import ascii_lowercase, ascii_uppercase
from math import log, gcd, sqrt, fabs, ceil, floor
from types import GeneratorType
from typing import TypeVar, List, Dict, Any, Callable


# Data structure
class SA:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __lt__(self, other):
        return self.x < other.x


# Constants
N = int(2e5 + 10)  # If using AR, modify accordingly
M = 20
INF = int(2e9)

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


# —————————————————————Division line ——————————————————————


class Solution:
    def smallestBeautifulString(self, s: str, k: int) -> str:
        for i in range(len(s) - 1, -1, -1):
            no_exist = set()

            # 任意字符的前两个字符如果不相等，说明没有回文，所以挑出来前两个字符
            for j in range(1, 3):
                if i - j >= 0:
                    no_exist.add(s[i - j])
            # 因为前面是两个字符，所以最多变三次，也就是这个字母加三次
            for j in range(1, 4):
                # 保证用的这个字符不超过 k ，并且这个字符不在不能用的字符中
                if std.letter_to_num(s[i]) + j + 1 <= k and chr(
                        ord(s[i]) + j) not in no_exist:
                    return self.gen_str(s, i, j)
        return ""

    def gen_str(self, s: str, idx: str, offset: str) -> str:
        res = list(s)
        res[idx] = chr(ord(res[idx]) + offset)

        for i in range(idx + 1, len(s)):
            no_exist = set()
            for j in range(1, 3):
                if i - j >= 0:
                    no_exist.add(res[i - j])
            for j in range(3):
                if chr(ord('a') + j) not in no_exist:
                    res[i] = chr(ord('a') + j)
                    break
        return ''.join(res)


Solution.smallestBeautifulString()
