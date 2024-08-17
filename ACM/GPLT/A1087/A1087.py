'''
Author: NEFU AB-IN
Date: 2024-08-15 23:57:49
FilePath: \GPLT\A1087\A1087.py
LastEditTime: 2024-08-17 21:06:27
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
    input = staticmethod(lambda: stdin.readline().strip())
    read = staticmethod(lambda: map(int, IO.input().split()))
    read_list = staticmethod(lambda: list(IO.read()))
    read_mixed = staticmethod(lambda *types: [t(v) for t, v in zip(types, IO.input().split())])


class Std:
    class Dijkstra:
        """Dijkstra's algorithm for finding the shortest path in a weighted graph, designed to compute various properties related to the shortest paths from a source node."""

        def __init__(self, n: int, val_: List):
            self.n = n  # Number of nodes in the graph
            self.val_ = val_  # Node values (weights associated with each node)
            self.g_ = Arr.graph(n)  # Adjacency list to store the graph
            self.dist_ = Arr.array(INF, n)  # Shortest distance from the source to each node
            self.sum_ = Arr.array(0, n)  # Sum of node values along the shortest path
            self.cnt_ = Arr.array(0, n)  # Count of shortest paths
            self.pre_ = Arr.array(0, n)  # Predecessor node in the shortest path
            self.num_ = Arr.array(0, n)  # Number of nodes in the shortest path

        def add_edge(self, u: int, v: int, w: int):
            """Add an edge to the graph."""
            self.g_[u].append((v, w))

        def dijkstra(self, s: int):
            """Dijkstra's algorithm for finding the shortest path in a graph.
            This method calculates the shortest distances, maximizes the sum of node values (`val_`) along the paths, and minimizes the number of edges (`num_`) used in the paths. Additionally, it counts the number of distinct shortest paths to each node."""
            st_ = Arr.array(0, self.n)
            q = []

            self.dist_[s] = 0
            self.sum_[s] = self.val_[s]
            self.cnt_[s] = self.num_[s] = 1
            heappush(q, (0, s))

            while q:
                _, u = heappop(q)
                if st_[u]:
                    continue
                st_[u] = 1
                for v, w in self.g_[u]:
                    if self.dist_[v] > self.dist_[u] + w:
                        self.dist_[v] = self.dist_[u] + w
                        self.pre_[v] = u
                        self.sum_[v] = self.sum_[u] + self.val_[v]
                        self.num_[v] = self.num_[u] + 1
                        self.cnt_[v] = self.cnt_[u]
                        heappush(q, (self.dist_[v], v))
                    elif self.dist_[v] == self.dist_[u] + w:
                        self.cnt_[v] += self.cnt_[u]
                        if self.sum_[u] > self.sum_[self.pre_[v]]:
                            self.pre_[v] = u
                            self.sum_[v] = self.sum_[u] + self.val_[v]
                            self.num_[v] = self.num_[u] + 1
                            heappush(q, (self.dist_[v], v))
                        elif self.sum_[u] == self.sum_[self.pre_[v]] and self.num_[v] > self.num_[u] + 1:
                            self.pre_[v] = u
                            self.num_[v] = self.num_[u] + 1
                            heappush(q, (self.dist_[v], v))

    class TrieNodeGraph:
        """TrieNode class can convert each string into an integer identifier, useful in graph theory."""
        _sid_cnt = 0  # sid counter, representing string index starting from 0
        _sid_to_word_ = {}  # Dictionary mapping sid to the original string

        def __init__(self):
            """Initialize children dictionary and cost. The trie tree is a 26-ary tree."""
            self._children_ = {}
            self._is_end_of_word = False  # Flag to indicate end of word
            self._sid = -1  # Unique ID for the node, -1 if not assigned

        def add(self, word: str) -> int:
            """Add a word to the trie and return a unique ID."""
            node = self
            for c in word:
                if c not in node._children_:
                    node._children_[c] = Std.TrieNodeGraph()
                node = node._children_[c]
            node._is_end_of_word = True  # Mark the end of the word
            if node._sid < 0:
                node._sid = self._sid_cnt
                self._sid_cnt += 1
            self._sid_to_word_[node._sid] = word
            return node._sid

        def _search(self, word: str) -> int:
            """Search for the exact word in the trie and return its unique ID, else -1."""
            node = self
            for c in word:
                if c not in node._children_:
                    return -1
                node = node._children_[c]
            return node._sid if node._is_end_of_word else -1

        def get_id(self, word: str) -> int:
            """Retrieve the unique ID for a given word."""
            return self._search(word)

        def get_str(self, sid: int) -> str:
            """Retrieve the original string associated with a given unique ID."""
            return word if (word := self._sid_to_word_.get(sid)) else "-1"
# ————————————————————— Division line ——————————————————————


n, k, st = IO.read_mixed(int, int, str)

trie = Std.TrieNodeGraph()
dj = Std.Dijkstra(n, Arr.array(0, n))
trie.add(st)

for i in range(n - 1):
    u, d = IO.read_mixed(str, int)
    index = trie.add(u)
    dj.val_[index] = d

for i in range(k):
    u, v, d = IO.read_mixed(str, str, int)
    dj.add_edge(trie.get_id(u), trie.get_id(v), d)
    dj.add_edge(trie.get_id(v), trie.get_id(u), d)

dj.dijkstra(trie.get_id(st))

ed_id = trie.get_id("ROM")

print(dj.cnt_[ed_id], dj.dist_[ed_id], dj.sum_[ed_id], dj.sum_[ed_id] // (dj.num_[ed_id] - 1))
stack_ = []

while ed_id != dj.pre_[ed_id]:
    stack_.append(ed_id)
    ed_id = dj.pre_[ed_id]

print(st, end="")
while stack_:
    print(f"->{trie.get_str(stack_.pop())}", end="")
