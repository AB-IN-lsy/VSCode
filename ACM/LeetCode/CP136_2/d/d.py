'''
Author: NEFU AB-IN
Date: 2024-08-03 22:09:32
FilePath: \LeetCode\CP136_2\d\d.py
LastEditTime: 2024-08-04 00:08:46
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
    class TreeDiameter:
        def __init__(self, n):
            self.graph = defaultdict(list)
            self.n = n
            self.dp = [0] * n  # DP array to store diameter from each node
            self.size = [0] * n
            self.max_dist_from_root = [0] * n  # To store max distances for re-rooting

        def add_edge(self, u, v, w):
            self.graph[u].append((v, w))
            self.graph[v].append((u, w))  # Since the graph is undirected
        
        def dfs1(self, node, parent):
            max1, max2 = 0, 0  # To store the two largest distances
            self.size[node] = 1
            for neighbor, weight in self.graph[node]:
                if neighbor != parent:
                    dist = self.dfs1(neighbor, node) + weight
                    if dist > max1:
                        max1, max2 = dist, max1
                    elif dist > max2:
                        max2 = dist
                    self.size[node] += self.size[neighbor]
            self.max_dist_from_root[node] = max1
            return max1
        
        def dfs2(self, node, parent):
            for neighbor, weight in self.graph[node]:
                if neighbor != parent:
                    self.dp[neighbor] = max(self.dp[node], self.max_dist_from_root[node] - (self.max_dist_from_root[neighbor] + weight)) + weight
                    self.dfs2(neighbor, node)

        def compute_diameters(self):
            # Perform DFS from an arbitrary node (0)
            self.dp[0] = self.dfs1(0, -1)
            # Perform DFS from the initial node to propagate diameter information
            self.dfs2(0, -1)
        
        def get_diameter_from(self, start_node):
            return self.dp[start_node]

# ————————————————————— Division line ——————————————————————


class Solution:
    def timeTaken(self, edges: List[List[int]]) -> List[int]:
        n = len(edges) + 1
        tr = Std.TreeDiameter(n)
        for u, v in edges:
            tr.add_edge(u, v, 2 if v % 2 == 0 else 1)
            tr.add_edge(v, u, 2 if u % 2 == 0 else 1)
        tr.compute_diameters()
        return [tr.get_diameter_from(i) for i in range(n)]
