'''
Author: NEFU AB-IN
Date: 2024-06-23 11:07:58
FilePath: \LeetCode\CP403\c\c.py
LastEditTime: 2024-06-23 16:41:12
'''
# Constants
from collections import deque

N = int(2e5 + 10)  # If using AR, modify accordingly
M = 20
INF = int(2e9)


# Func
class std:

    letter_to_num = staticmethod(lambda x: ord(x.upper()) - 65)  # A -> 0
    array = staticmethod(lambda x=0, size=N: [x] * size)
    array2d = staticmethod(
        lambda x=0, rows=N, cols=M: [std.array(x, cols) for _ in range(rows)])
    max = staticmethod(lambda a, b: a if a > b else b)
    min = staticmethod(lambda a, b: a if a < b else b)
    filter = staticmethod(lambda func, iterable: list(filter(func, iterable)))


# —————————————————————Division line ——————————————————————

# dp[i] = max(dp[i], dp[j] + cost(j + 1, i))


class Solution:

    def maximumTotalCost(self, nums: list[int]) -> int:
        a, b = 0, -INF
        for x in nums:
            ta = max(a + x, b - x)
            tb = max(a + x, b + x)
            a, b = ta, tb
        return max(a, b)
