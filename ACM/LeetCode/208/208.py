'''
Author: NEFU AB-IN
Date: 2024-08-17 20:50:20
FilePath: \LeetCode\208\208.py
LastEditTime: 2024-08-17 20:53:35
'''
# 3.8.19 import
import random
from collections import Counter, defaultdict, deque
from datetime import datetime, timedelta
from functools import lru_cache, reduce
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from itertools import combinations, compress, permutations, starmap, tee
from math import ceil, comb, fabs, floor, gcd, hypot, log, perm, sqrt
from string import ascii_lowercase, ascii_uppercase
from sys import exit, setrecursionlimit, stdin
from typing import Any, Callable, Dict, List, Optional, Tuple, TypeVar, Union

# Constants
TYPE = TypeVar('TYPE')
N = int(2e5 + 10)
M = int(20)
INF = int(1e12)
OFFSET = int(100)
MOD = int(1e9 + 7)

# Set recursion limit
setrecursionlimit(int(2e9))


class Arr:
    array = staticmethod(lambda x=0, size=N: [x() if callable(x) else x for _ in range(size)])
    array2d = staticmethod(lambda x=0, rows=N, cols=M: [Arr.array(x, cols) for _ in range(rows)])
    graph = staticmethod(lambda size=N: [[] for _ in range(size)])


class Math:
    max = staticmethod(lambda a, b: a if a > b else b)
    min = staticmethod(lambda a, b: a if a < b else b)


class IO:
    input = staticmethod(lambda: stdin.readline().rstrip("\r\n"))
    read = staticmethod(lambda: map(int, IO.input().split()))
    read_list = staticmethod(lambda: list(IO.read()))


class Std:
    class TrieNode:
        """TrieNode class can quickly process string prefixes, a common feature used in applications like autocomplete and spell checking."""
        _sid_cnt = 0  # sid counter, representing string index starting from 0

        def __init__(self):
            """Initialize children dictionary and cost. The trie tree is a 26-ary tree."""
            self._children_ = {}
            self._cost = INF
            self._is_end_of_word = False  # Flag to indicate end of word
            self._sid = -1  # Unique ID for the node, -1 if not assigned

        def add(self, word: str, cost: int) -> int:
            """Add a word to the trie with the associated cost and return a unique ID."""
            node = self
            for c in word:
                if c not in node._children_:
                    node._children_[c] = Std.TrieNode()
                node = node._children_[c]
            node._cost = Math.min(node._cost, cost)
            node._is_end_of_word = True  # Mark the end of the word
            if node._sid < 0:
                node._sid = self._sid_cnt
                self._sid_cnt += 1
            return node._sid

        def search(self, word: str) -> List[List]:
            """Search for prefixes of 'word' in the trie and return their lengths, costs, and sids.

            Collects ALL prefix lengths and their associated costs and sids!! 
            Valid matches are those where node.cost != INF and node.sid != -1.
            """
            node = self
            ans = []
            for i, c in enumerate(word):
                if c not in node._children_:
                    break
                node = node._children_[c]
                ans.append([i + 1, node.cost, node.sid])  # i + 1 to denote length from start
            return ans

        def search_exact(self, word: str) -> int:
            """Search for the exact word in the trie and return its cost or unique ID."""
            node = self
            for c in word:
                if c not in node._children_:
                    return INF
                node = node._children_[c]
            return node._cost if node._is_end_of_word else INF

# ————————————————————— Division line ——————————————————————


class Trie:

    def __init__(self):
        self.trie = Std.TrieNode()

    def insert(self, word: str) -> None:
        self.trie.add(word, 0)

    def search(self, word: str) -> bool:
        return True if self.trie.search_exact(word) != INF else False

    def startsWith(self, prefix: str) -> bool:
        ans = self.trie.search(prefix)
        return len(ans) == len(prefix)
