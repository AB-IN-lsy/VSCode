'''
Author: NEFU AB-IN
Date: 2024-08-12 22:56:55
FilePath: \LeetCode\676\676.py
LastEditTime: 2024-08-12 23:26:38
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
        """
        TrieNode class can convert each string into an integer identifier, useful in graph theory.
        It can also quickly process string prefixes, a common feature used in applications like autocomplete and spell checking.
        """
        sid_cnt = 0  # sid counter, representing string index starting from 0

        def __init__(self):
            """Initialize children dictionary and cost. The trie tree is a 26-ary tree."""
            self.children = {}
            self.is_end_of_word = False  # Flag to indicate end of word
            self.sid = -1  # Unique ID for the node, -1 if not assigned

        def add(self, word):
            """Add a word to the trie with the associated cost and return a unique ID."""
            node = self
            for c in word:
                if c not in node.children:
                    node.children[c] = Std.TrieNode()
                node = node.children[c]
            node.is_end_of_word = True  # Mark the end of the word
            if node.sid < 0:
                node.sid = self.sid_cnt
                self.sid_cnt += 1
            return node.sid

        def search(self, word: str, return_type: str = 'cost'):
            """Search for the exact word in the trie and return its cost or unique ID.

            Args:
                word (str): The word to search for.
                return_type (str): The type of value to return. Can be 'cost' or 'sid'.

            Returns:
                int: The cost or unique ID of the word, or INF / -1 if not found.
            """
            node = self
            for c in word:
                if c not in node.children:
                    return INF if return_type == 'cost' else -1
                node = node.children[c]
            if node.is_end_of_word:
                return node.cost if return_type == 'cost' else node.sid
            else:
                return INF if return_type == 'cost' else -1
# ————————————————————— Division line ——————————————————————


class MagicDictionary:

    def __init__(self):
        self.trie = Std.TrieNode()

    def buildDict(self, dictionary: List[str]) -> None:
        for dic in dictionary:
            self.trie.add(dic)

    def search(self, searchWord: str) -> bool:
        searchWord = list(searchWord)
        for i, old in enumerate(searchWord):
            for new in ascii_lowercase:
                if old == new:
                    continue
                searchWord[i] = new
                if self.trie.search("".join(searchWord), 'sid') != -1:
                    return True
                searchWord[i] = old
        return False


magicDictionary = MagicDictionary()
magicDictionary.buildDict(["hello", "leetcode"])
magicDictionary.search("hello")
magicDictionary.search("hhllo")
magicDictionary.search("hell")
magicDictionary.search("leetcoded")
