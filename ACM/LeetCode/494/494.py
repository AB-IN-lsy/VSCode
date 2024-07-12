'''
Author: NEFU AB-IN
Date: 2024-06-30 21:25:56
FilePath: \LeetCode\494\494.py
LastEditTime: 2024-07-11 22:25:35
'''
# 3.8.19 import
import random
from collections import Counter, defaultdict, deque
from datetime import datetime, timedelta
from functools import lru_cache
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from itertools import combinations, compress, permutations, starmap, tee
from math import ceil, comb, fabs, floor, gcd, log, perm, sqrt
from string import ascii_lowercase, ascii_uppercase
from sys import exit, setrecursionlimit, stdin
from typing import Any, Dict, List, Tuple, TypeVar, Union

# Constants
TYPE = TypeVar('TYPE')
N = int(2e5 + 10)  # If using AR, modify accordingly
M = int(20)  # If using AR, modify accordingly
INF = int(2e9)
OFFSET = int(100)
MOD = int(1e9 + 7)

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
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        n = len(nums)
        cnt = 0  # 计数器在外部定义

        @lru_cache(None)
        def dfs(index: int, current_sum: int):
            nonlocal cnt  # 使用 nonlocal 来引用外部的 cnt
            if index == n:
                if current_sum == target:
                    cnt += 1
                return

            # 对当前元素进行加法和减法两种选择，并递归处理下一个元素
            dfs(index + 1, current_sum + nums[index])
            dfs(index + 1, current_sum - nums[index])

        dfs(0, 0)  # 从第一个元素开始，总和初始化为0
        return cnt

    def findTargetSumWays(self, nums, target):
        sum_nums = sum(nums)
        # 目标和 target 必须在范围 [-sum_nums, sum_nums] 之间
        if target > sum_nums or target < -sum_nums:
            return 0

        dp = Arr.array(0, 2 * sum_nums + 1)
        dp[sum_nums] = 1  # 初始条件：sum 为 0 的方案数为 1

        for num in nums:
            next_dp = Arr.array(0, 2 * sum_nums + 1)
            for sum_ in range(num, 2 * sum_nums - num + 1):
                next_dp[sum_ + num] += dp[sum_]
                next_dp[sum_ - num] += dp[sum_]
            dp = next_dp

        return dp[sum_nums + target]

    def findTargetSumWays(self, nums, target):
        total_sum = sum(nums)
        if (total_sum - target) % 2 != 0 or total_sum < target:
            return 0
        target_sum = (total_sum - target) // 2

        dp = [0] * (target_sum + 1)
        dp[0] = 1

        for num in nums:
            for j in range(target_sum, num - 1, -1):
                dp[j] += dp[j - num]

        return dp[target_sum]

    def findTargetSumWays(self, nums, target):
        n = len(nums)
        total_sum = sum(nums)
        if (total_sum - target) % 2 != 0 or total_sum < target:
            return 0
        target_sum = (total_sum - target) // 2

        @lru_cache(None)
        def dfs(i, c):
            if i < 0:
                return 1 if c == 0 else 0
            if c < nums[i]:
                return dfs(i - 1, c)
            return dfs(i - 1, c) + dfs(i - 1, c - nums[i])

        return dfs(n - 1, target_sum)
