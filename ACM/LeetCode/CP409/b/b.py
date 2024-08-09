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
    class Func:
        @staticmethod
        def pairwise(iterable):
            """Return successive overlapping pairs taken from the input iterable."""
            a, b = tee(iterable)
            next(b, None)
            return zip(a, b)
            
    class GraphShortestPath:
        def __init__(self, n: int):
            self.n = n
            self.g = Arr.graph(n)
                
        def add_edge(self, u: int, v: int, w: int):
            """Add an edge to the graph."""
            self.g[u].append((v, w))
    
        def dijkstra(self, s: int) -> List[int]:
            """Dijkstra's algorithm for finding the shortest path in a graph."""
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
    
            return dist


# ————————————————————— Division line ——————————————————————
class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        st = Std.GraphShortestPath(n)
        for u, v in Std.Func.pairwise(range(n)):
            st.add_edge(u, v, 1)
        ans = []
        for u, v in queries:
            st.add_edge(u, v, 1)
            dist = st.dijkstra(0)
            ans.append(dist[n - 1])
        return ans