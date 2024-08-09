'''
Author: NEFU AB-IN
Date: 2024-07-12 20:08:05
FilePath: \LeetCode\2977\2977.py
LastEditTime: 2024-07-13 18:32:37
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
    class GraphShortestPath:
        def __init__(self, n: int):
            self.n = n
            self.g = Arr.graph(n)
            self.spfa_cache = {}
            self.dijkstra_cache = {}
            self.floyd_cache = None

        def add_edge(self, u: int, v: int, w: int):
            """Add an edge to the graph."""
            self.g[u].append((v, w))

        def spfa(self, s: int) -> List[int]:
            """SPFA (Shortest Path Faster Algorithm) for finding the shortest path in a graph."""
            if s in self.spfa_cache:
                return self.spfa_cache[s]

            dist = Arr.array(INF, self.n)
            st = Arr.array(0, self.n)
            q = deque()

            dist[s] = 0
            q.appendleft(s)
            st[s] = 1

            while q:
                u = q.pop()
                st[u] = 0
                for v, w in self.g[u]:
                    if dist[v] > dist[u] + w:
                        dist[v] = dist[u] + w
                        if st[v] == 0:
                            q.appendleft(v)
                            st[v] = 1

            self.spfa_cache[s] = dist
            return dist

        def dijkstra(self, s: int) -> List[int]:
            """Dijkstra's algorithm for finding the shortest path in a graph."""
            if s in self.dijkstra_cache:
                return self.dijkstra_cache[s]

            dist = Arr.array(INF, self.n)
            st = Arr.array(0, self.n)
            q = []

            dist[s] = 0
            heappush(q, (0, s))

            while q:
                d, u = heappop(q)
                if st[u]:
                    continue
                st[u] = 1
                for v, w in self.g[u]:
                    if dist[v] > dist[u] + w:
                        dist[v] = dist[u] + w
                        heappush(q, (dist[v], v))

            self.dijkstra_cache[s] = dist
            return dist

        def floyd(self) -> List[List[int]]:
            """Floyd's algorithm for finding the shortest paths between all pairs of nodes."""
            if self.floyd_cache is not None:
                return self.floyd_cache

            dist = Arr.array2d(INF, self.n, self.n)
            # Initialize distances with the given edges
            for u in range(self.n):
                for v, w in self.g[u]:
                    dist[u][v] = Math.min(dist[u][v], w)

            # Set the diagonal to zero
            for i in range(self.n):
                dist[i][i] = 0

            # Floyd-Warshall algorithm
            for k in range(self.n):
                for i in range(self.n):
                    if dist[i][k] == INF:  # If there is no path from i to k, skip
                        continue
                    for j in range(self.n):
                        if dist[i][j] > dist[i][k] + dist[k][j]:
                            dist[i][j] = dist[i][k] + dist[k][j]

            self.floyd_cache = dist
            return dist

        def shortest_path(self, x: int, y: int, method: str = 'dijkstra') -> int:
            """Calculate the shortest path from node x to node y using the specified method."""
            if method == 'spfa':
                dist = self.spfa(x)
            elif method == 'dijkstra':
                dist = self.dijkstra(x)
            elif method == 'floyd':
                dist_matrix = self.floyd()
                return dist_matrix[x][y] if dist_matrix[x][y] < INF // 2 else INF
            else:
                raise ValueError("Unsupported method. Use 'spfa', 'dijkstra', or 'floyd'.")

            return dist[y]

    class TrieNode:
        """
        TrieNode class can convert each string into an integer identifier, useful in graph theory.
        It can also quickly process string prefixes, a common feature used in applications like autocomplete and spell checking.
        """
        sid_cnt = 0  # sid counter, representing string index starting from 0

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
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        trie = Std.TrieNode()
        edges = []
        for u, v, w in zip(original, changed, cost):
            x, y = trie.add(u, 0), trie.add(v, 0)
            edges.append((x, y, w))

        short_path = Std.GraphShortestPath(trie.sid_cnt)
        for u, v, w in edges:
            short_path.add_edge(u, v, w)

        n = len(source)

        @lru_cache(None)
        def dfs(l: int):
            if l >= n:
                return 0
            res = INF
            if source[l] == target[l]:
                res = dfs(l + 1)

            for (len_, _, x), (_, _, y) in zip(trie.search(source[l:]), trie.search(target[l:])):
                if x != -1 and y != -1:
                    res = Math.min(res, short_path.shortest_path(x, y, 'floyd') + dfs(l + len_))
            return res

        ans = dfs(0)

        return ans if ans != INF else -1


print(Solution().minimumCost("abcdefgh", "acdeeghh", ["bcd", "fgh", "thh"], ["cde", "thh", "ghh"], [1, 3, 5]))
print(Solution().minimumCost("abcd", "acbe", ["a", "b", "c", "c", "e", "d"], ["b", "c", "b", "e", "b", "e"], [2, 5, 5, 1, 2, 20]))
