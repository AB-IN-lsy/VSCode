# 3.8.19 import
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
    
    @staticmethod
    def bisect_left(a, x, key=lambda y: y):
        """The insertion point is the first position where the element is not less than x."""
        left, right = 0, len(a)
        while left < right:
            mid = (left + right) >> 1
            if key(a[mid]) < x:
                left = mid + 1
            else:
                right = mid
        return left

    @staticmethod
    def bisect_right(a, x, key=lambda y: y):
        """The insertion point is the first position where the element is greater than x."""
        left, right = 0, len(a)
        while left < right:
            mid = (left + right) >> 1
            if key(a[mid]) <= x:
                left = mid + 1
            else:
                right = mid
        return left
    
    class SparseTable:
        def __init__(self, data: list, func=lambda x, y: x | y):
            """Initialize the Sparse Table with the given data and function."""
            self.func = func
            self.st = [list(data)]
            i, n = 1, len(self.st[0])
            while 2 * i <= n:
                pre = self.st[-1]
                self.st.append([func(pre[j], pre[j + i]) for j in range(n - 2 * i + 1)])
                i <<= 1

        def query(self, begin: int, end: int):
            """Query the combined result over the interval [begin, end]."""
            lg = (end - begin + 1).bit_length() - 1
            return self.func(self.st[lg][begin], self.st[lg][end - (1 << lg) + 1])

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

    class StringHash:
        def __init__(self, s: str, mod: int = 1_070_777_777):
            """Initialize the StringHash object with the string, base, and mod."""
            self.s = s
            self.mod = mod
            self.base = random.randint(8 * 10 ** 8, 9 * 10 ** 8)
            self.n = len(s)
            self.pow_base = [1] + Arr.array(0, self.n)  # pow_base[i] = BASE^i
            self.pre_hash = Arr.array(0, self.n + 1)  # pre_hash[i] = hash(s[:i])
            self._compute_hash()

        def _compute_hash(self):
            """Compute the prefix hash values and power of base values for the string."""
            for i, b in enumerate(self.s):
                self.pow_base[i + 1] = self.pow_base[i] * self.base % self.mod
                self.pre_hash[i + 1] = (self.pre_hash[i] * self.base + ord(b)) % self.mod

        def get_sub_hash(self, l: int, r: int) -> int:
            """Get the hash value of the substring s[l:r+1] """
            return (self.pre_hash[r + 1] - self.pre_hash[l] * self.pow_base[r - l + 1] % self.mod + self.mod) % self.mod

        def get_full_hash(self) -> int:
            """Get the hash value of the full string"""
            return self.pre_hash[self.n]

        def compute_hash(self, word: str) -> int:
            """Compute the hash value of a given word using the object's base and mod."""
            h = 0
            for b in word:
                h = (h * self.base + ord(b)) % self.mod
            return h

# ————————————————————— Division line ——————————————————————

class Solution:
    def minimumCost(self, target: str, words: List[str], costs: List[int]) -> int:
        # Build the Trie
        trie = Std.TrieNode()
        for word, cost in zip(words, costs):
            trie.add(word, cost)
        
        n = len(target)
        dp = Arr.array(INF, n + 1)
        dp[0] = 0
        
        # Dynamic programming to calculate the minimum cost
        for i in range(n):
            if dp[i] == INF:
                continue
            for length, cost in trie.search(target[i:]):
                dp[i + length] = min(dp[i + length], dp[i] + cost)
        
        return dp[n] if dp[n] != INF else -1

class Solution:
    def minimumCost(self, target: str, words: List[str], costs: List[int]) -> int:
        n = len(target)

        target_hash = Std.StringHash(target)

        # 每个 words[i] 的哈希值 -> 最小成本
        min_cost = defaultdict(lambda: INF)
        for w, c in zip(words, costs):
            h = target_hash.compute_hash(w)
            min_cost[h] = min(min_cost[h], c)

        # 获取所有唯一的单词长度
        sorted_lens = sorted(set(map(len, words)))

        dp = Arr.array(INF, n + 1)
        dp[0] = 0
        
        for i in range(n):
            if dp[i] == INF:
                continue
            for sz in sorted_lens:
                if i + sz > n:
                    break
                # 计算子串 target[i:i+sz] 的哈希值
                sub_hash = target_hash.get_sub_hash(i, i + sz - 1)
                dp[i + sz] = min(dp[i + sz], dp[i] + min_cost[sub_hash])

        return -1 if dp[n] == INF else dp[n]