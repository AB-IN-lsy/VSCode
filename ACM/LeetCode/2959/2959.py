'''
Author: NEFU AB-IN
Date: 2024-07-17 15:46:10
FilePath: \LeetCode\2959\2959.py
LastEditTime: 2024-07-17 16:16:35
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

        def add_edge(self, u: int, v: int, w: int):
            """Add an edge to the graph."""
            self.g[u].append((v, w))

        def floyd(self, exclude_nodes=None) -> List[List[int]]:
            """Floyd's algorithm for finding the shortest paths between all pairs of nodes."""
            if exclude_nodes is None:
                exclude_nodes = []

            dist = Arr.array2d(INF, self.n, self.n)
            # Initialize distances with the given edges
            for u in range(self.n):
                if u in exclude_nodes:
                    continue
                for v, w in self.g[u]:
                    if v in exclude_nodes:
                        continue
                    dist[u][v] = Math.min(dist[u][v], w)

            # Set the diagonal to zero
            for i in range(self.n):
                if i in exclude_nodes:
                    continue
                dist[i][i] = 0

            # Floyd-Warshall algorithm
            for k in range(self.n):
                for i in range(self.n):
                    if dist[i][k] == INF:  # If there is no path from i to k, skip
                        continue
                    for j in range(self.n):
                        if dist[i][j] > dist[i][k] + dist[k][j]:
                            dist[i][j] = dist[i][k] + dist[k][j]

            return dist

# ————————————————————— Division line ——————————————————————


class Solution:
    def numberOfSets(self, n: int, maxDistance: int, roads: List[List[int]]) -> int:

        def judge(dist, exclude):
            for u in range(n):
                if u in exclude:
                    continue
                for v in range(n):
                    if v in exclude:
                        continue
                    if dist[u][v] > maxDistance:
                        return 0
            return 1

        graph = Std.GraphShortestPath(n)
        for u, v, w in roads:
            graph.add_edge(u, v, w)
            graph.add_edge(v, u, w)
        ans = 0
        for i in range(1 << n):
            exclude = set()
            for j in range(n):
                if i & 1 << j:
                    exclude.add(j)
            dist = graph.floyd(exclude)
            ans += judge(dist, exclude)

        return ans


Solution().numberOfSets(3, 5, [[0, 1, 2], [1, 2, 10], [0, 2, 10]])
