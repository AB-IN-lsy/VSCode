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
            self.dijkstra_cache = {}

        def add_edge(self, u: int, v: int, w: int):
            """Add an edge to the graph."""
            self.g[u].append((v, w))

        def dijkstra(self, s: int, disappear) -> List[int]:
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
                    if dist[v] > dist[u] + w and dist[u] + w < disappear[v]:
                        dist[v] = dist[u] + w
                        heappush(q, (dist[v], v))

            self.dijkstra_cache[s] = dist
            return dist


# ————————————————————— Division line ——————————————————————


class Solution:
    def minimumTime(self, n: int, edges: List[List[int]], disappear: List[int]) -> List[int]:
        graph = Std.GraphShortestPath(n)
        for u, v, w in edges:
            graph.add_edge(u, v, w)
            graph.add_edge(v, u, w)

        dist = [dis if dis != INF else -1 for dis in graph.dijkstra(0, disappear)]
        return dist


Solution().minimumTime(3, [[0, 1, 2], [1, 2, 1], [0, 2, 4]], [1, 1, 5])
