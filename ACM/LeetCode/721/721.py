'''
Author: NEFU AB-IN
Date: 2024-07-15 10:35:24
FilePath: \LeetCode\721\721.py
LastEditTime: 2024-07-15 14:21:11
'''
import random
from collections import Counter, defaultdict, deque, namedtuple
# 3.8.19 import
from dataclasses import dataclass, field
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
    class UnionFind:
        def __init__(self, size, data=None):
            """Union-Find data structure."""
            self.size = size
            self.parent = list(range(size))  # Parent pointers
            self.rank = Arr.array(1, size)  # Rank (approximate tree height)
            self.data = data if data else None  # Data arrays for each node

        def find(self, p):
            """Find the root of the element p with path compression."""
            if self.parent[p] != p:
                self.parent[p] = self.find(self.parent[p])  # Path compression
            return self.parent[p]

        def union(self, p, q):
            """Union the sets containing p and q using union by rank and merge data if available."""
            rootP = self.find(p)
            rootQ = self.find(q)

            if rootP != rootQ:
                # Union by rank
                if self.rank[rootP] > self.rank[rootQ]:
                    self.parent[rootQ] = rootP
                    if self.data:
                        self.data[rootP].extend(self.data[rootQ])  # Merge data arrays
                    return rootP
                elif self.rank[rootP] < self.rank[rootQ]:
                    self.parent[rootP] = rootQ
                    if self.data:
                        self.data[rootQ].extend(self.data[rootP])  # Merge data arrays
                    return rootQ
                else:
                    self.parent[rootQ] = rootP
                    if self.data:
                        self.data[rootP].extend(self.data[rootQ])  # Merge data arrays
                    self.rank[rootP] += 1
                    return rootP
            return rootP  # They are already in the same set

    class TrieNode:
        """
        TrieNode class can convert each string into an integer identifier, useful in graph theory.
        It can also quickly process string prefixes, a common feature used in applications like autocomplete and spell checking.
        """
        sid_cnt = 0  # sid counter, representing string index starting from 0
        sid_to_string = {}  # Mapping from sid to string

        def __init__(self):
            """Initialize children dictionary and cost. The trie tree is a 26-ary tree."""
            self.children = {}
            self.cost = INF
            self.is_end_of_word = False  # Flag to indicate end of word
            self.sid = -1  # Unique ID for the node, -1 if not assigned

        def add(self, word, cost):
            """Add a word to the trie with the associated cost and return a unique ID."""
            node = self
            for c in word:
                if c not in node.children:
                    node.children[c] = Std.TrieNode()
                node = node.children[c]
            node.cost = Math.min(node.cost, cost)
            node.is_end_of_word = True  # Mark the end of the word
            if node.sid < 0:
                node.sid = self.sid_cnt
                self.sid_to_string[node.sid] = word
                self.sid_cnt += 1
            return node.sid

        def search(self, word: str):
            """Search for prefixes of 'word' in the trie and return their lengths, costs, and sids.

            !! Collects all prefix lengths and their associated costs and sids.
            Valid matches are those where node.cost != INF and node.sid != -1.
            """
            node = self
            ans = []
            for i, c in enumerate(word):
                if c not in node.children:
                    break
                node = node.children[c]
                ans.append([i + 1, node.cost, node.sid])  # i + 1 to denote length from start
            return ans

        def search_exact(self, word: str, return_type: str = 'cost'):
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


class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        def find_ones_positions(n: int) -> List[int]:
            positions = []
            index = 0
            while n > 0:
                if n & 1:
                    positions.append(index)
                n >>= 1
                index += 1
            return positions

        @dataclass
        class Account:
            emails: List[str]
            bit: int = 0

        dic = defaultdict(list)

        for account in accounts:
            dic[account[0]].append(Account(account[1:], 0))

        ans = []
        for name, accounts_ in dic.items():
            accounts_: List[Account]
            trie = Std.TrieNode()
            uf = Std.UnionFind(len(accounts_))

            for account in accounts_:
                for email in account.emails:
                    sid = trie.add(email, 0)
                    account.bit |= 1 << sid

            for i, account_x in enumerate(accounts_):
                for j, account_y in enumerate(accounts_):
                    if i != j and account_x.bit & account_y.bit:
                        root = uf.union(i, j)
                        accounts_[root].bit |= accounts_[i].bit
                        accounts_[root].bit |= accounts_[j].bit

            for i in range(uf.size):
                res = [name]
                emails = set()
                if uf.parent[i] == i:
                    positions = find_ones_positions(accounts_[i].bit)
                    for sid in positions:
                        emails.add(trie.sid_to_string[sid])
                    ans.append(res + sorted(emails))

        return ans
