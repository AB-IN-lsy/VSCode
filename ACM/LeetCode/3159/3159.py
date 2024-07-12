# 3.8.19 import
import random
from collections import Counter, defaultdict, deque
from datetime import datetime, timedelta
from functools import lru_cache
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from itertools import combinations, compress, permutations, starmap, tee
from math import ceil, fabs, floor, gcd, log, sqrt
from string import ascii_lowercase, ascii_uppercase
from sys import exit, setrecursionlimit, stdin
from typing import Any, Dict, List, Tuple, TypeVar, Union

# Constants
TYPE = TypeVar('TYPE')
N = int(2e5 + 10)  # If using AR, modify accordingly
M = int(20)  # If using AR, modify accordingly
INF = int(2e9)
OFFSET = int(100)

# Set recursion limit
setrecursionlimit(INF)

class Arr:
    array = staticmethod(lambda x=0, size=N: [x] * size)
    array2d = staticmethod(lambda x=0, rows=N, cols=M: [Arr.array(x, cols) for _ in range(rows)])
    graph = staticmethod(lambda size=N: [[] for _ in range(size)])
    @staticmethod
    def to_1_indexed(data: Union[List, str, List[List]]):
        """Adds a zero prefix to the data and returns the modified data and its length."""
        if isinstance(data, list):
            if all(isinstance(item, list) for item in data):  # Check if it's a 2D array
                new_data = [[0] * (len(data[0]) + 1)] + [[0] + row for row in data]
                return new_data, len(new_data) - 1, len(new_data[0]) - 1
            else:
                new_data = [0] + data
                return new_data, len(new_data) - 1
        elif isinstance(data, str):
            new_data = '0' + data
            return new_data, len(new_data) - 1
        else:
            raise TypeError("Input must be a list, a 2D list, or a string")

class Str:
    letter_to_num = staticmethod(lambda x: ord(x.upper()) - 65)  # A -> 0
    num_to_letter = staticmethod(lambda x: ascii_uppercase[x])  # 0 -> A
    removeprefix = staticmethod(lambda s, prefix: s[len(prefix):] if s.startswith(prefix) else s)
    removesuffix = staticmethod(lambda s, suffix: s[:-len(suffix)] if s.endswith(suffix) else s)

class Math:
    max = staticmethod(lambda a, b: a if a > b else b)
    min = staticmethod(lambda a, b: a if a < b else b)

class IO:
    input = staticmethod(lambda: stdin.readline().rstrip("\r\n"))
    read = staticmethod(lambda: map(int, IO.input().split()))
    read_list = staticmethod(lambda: list(IO.read()))

class Std:
    pass

class GraphShortestPath:
    def __init__(self, n: int):
        self.n = n
        self.g = Arr.graph(n)
    
    def add_edge(self, u: int, v: int, w: int):
        """Add an edge to the graph."""
        self.g[u].append((v, w))
    
    def spfa(self, s: int) -> List[int]:
        """SPFA (Shortest Path Faster Algorithm) for finding the shortest path in a graph."""
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
        return dist
    
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

    def floyd(self) -> List[List[int]]:
        """Floyd's algorithm for finding the shortest paths between all pairs of nodes."""
        dist = Arr.array2d(INF, self.n, self.n)
        
        # Initialize distances with the given edges
        for u in range(self.n):
            for v, w in self.g[u]:
                dist[u][v] = w
        
        # Set the diagonal to zero
        for i in range(self.n):
            dist[i][i] = 0
        
        # Floyd-Warshall algorithm
        for k in range(self.n):
            for i in range(self.n):
                for j in range(self.n):
                    if dist[i][j] > dist[i][k] + dist[k][j]:
                        dist[i][j] = dist[i][k] + dist[k][j]
        
        return dist

    def shortest_path(self, x: int, y: int, method: str = 'dijkstra') -> int:
        """Calculate the shortest path from node x to node y using the specified method."""
        if method == 'spfa':
            dist = self.spfa(x)
        elif method == 'dijkstra':
            dist = self.dijkstra(x)
        elif method == 'floyd':
            dist_matrix = self.floyd()
            if dist[x][y] > INF // 2:
                return INF
            else:
                return dist_matrix[x][y]
        else:
            raise ValueError("Unsupported method. Use 'spfa', 'dijkstra', or 'floyd'.")
        
        return dist[y]

# ————————————————————— Division line ——————————————————————

class Solution:
    def occurrencesOfElement(self, nums: List[int], queries: List[int], x: int) -> List[int]:
        
        cnt_ = Counter()
        cnt = 0
        for i, num in enumerate(nums):
            if num == x:
                cnt += 1
                cnt_[cnt] = i
        
        ans = []
        for query in queries:
            if query > cnt:
                ans.append(-1)
            else:
                ans.append(cnt_[query])
        return ans