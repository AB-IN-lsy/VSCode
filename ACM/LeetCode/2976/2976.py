'''
Author: NEFU AB-IN
Date: 2024-07-12 16:46:54
FilePath: \LeetCode\2976\2976.py
LastEditTime: 2024-07-12 17:40:05
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


class Str:
    atoi = staticmethod(lambda x: ord(x.upper()) - 65)  # A -> 0
    itoa = staticmethod(lambda x: ascii_uppercase[x])  # 0 -> A
    removeprefix = staticmethod(lambda s, prefix: s[len(prefix):] if s.startswith(prefix) else s)
    removesuffix = staticmethod(lambda s, suffix: s[:-len(suffix)] if s.endswith(suffix) else s)


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

# ————————————————————— Division line ——————————————————————


class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        short_path = Std.GraphShortestPath(26)
        for u, v, w in zip(original, changed, cost):
            u, v, w = Str.atoi(u), Str.atoi(v), w
            short_path.add_edge(u, v, w)

        dist = short_path.floyd()
        res = 0
        for sc, tc in zip(source, target):
            sc, tc = Str.atoi(sc), Str.atoi(tc)
            if dist[sc][tc] < INF // 2:
                res += dist[sc][tc]
            else:
                return -1

        return res
