'''
Author: NEFU AB-IN
Date: 2024-07-09 14:50:11
FilePath: \LeetCode\3102\3102.py
LastEditTime: 2024-07-09 16:53:59
'''
import random
from collections import Counter, defaultdict, deque
from datetime import datetime, timedelta
from functools import lru_cache
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from itertools import combinations, compress, permutations, starmap, tee
from math import ceil, fabs, floor, gcd, log, sqrt
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
    class TrieNode:
        def __init__(self):
            """Initialize children dictionary and cost. The trie tree is a 26-ary tree."""
            self.children = {}
            self.cost = INF
    
        def add(self, word, cost):
            """Add a word to the trie with the associated cost."""
            node = self
            for c in word:
                if c not in node.children:
                    node.children[c] = Std.TrieNode()
                node = node.children[c]
            node.cost = min(node.cost, cost)
    
        def search(self, word):
            """Search for prefixes of 'word' in the trie and return their lengths and costs."""
            node = self
            ans = []
            for i, c in enumerate(word):
                if c not in node.children:
                    break
                node = node.children[c]
                if node.cost != INF:
                    ans.append([i + 1, node.cost])  # i + 1 to denote length from start
            return ans

# ————————————————————— Division line ——————————————————————

class Solution:
    def minimumDistance(self, points: List[List[int]]) -> int:
        n = len(points)
        A = [x + y for x, y in points]
        B = [x - y for x, y in points]

        A_min_st = Std.SparseTable(A, Math.min)
        A_max_st = Std.SparseTable(A, Math.max)
        B_min_st = Std.SparseTable(B, Math.min)
        B_max_st = Std.SparseTable(B, Math.max)

        def get_max_distance_without_index(index):
            if index == 0:
                min_A = A_min_st.query(index + 1, n - 1)
                max_A = A_max_st.query(index + 1, n - 1)
                min_B = B_min_st.query(index + 1, n - 1)
                max_B = B_max_st.query(index + 1, n - 1)
            elif index == n - 1:
                min_A = A_min_st.query(0, index - 1)
                max_A = A_max_st.query(0, index - 1)
                min_B = B_min_st.query(0, index - 1)
                max_B = B_max_st.query(0, index - 1)
            else:
                min_A = Math.min(A_min_st.query(0, index - 1), A_min_st.query(index + 1, n - 1))
                max_A = Math.max(A_max_st.query(0, index - 1), A_max_st.query(index + 1, n - 1))
                min_B = Math.min(B_min_st.query(0, index - 1), B_min_st.query(index + 1, n - 1))
                max_B = Math.max(B_max_st.query(0, index - 1), B_max_st.query(index + 1, n - 1))
            
            return Math.max(max_A - min_A, max_B - min_B)
        
        result = INF
        
        for i in range(len(points)):
            result = Math.min(result, get_max_distance_without_index(i))

        return result