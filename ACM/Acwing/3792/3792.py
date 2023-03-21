'''
Author: NEFU AB-IN
Date: 2023-03-19 20:16:20
FilePath: \Acwing\3792\3792.py
LastEditTime: 2023-03-19 20:33:25
'''
read = lambda: map(int, input().split())
from collections import Counter, deque
from heapq import heappop, heappush
from itertools import permutations

N = int(1e3 + 10)
INF = int(2e9)

st, prime = [0] * N, []
vis = [0] * N
cnt = 0


def init():
    for i in range(2, N):
        if st[i] == 0:
            prime.append(i)
        j = 0
        while prime[j] * i < N:
            st[prime[j] * i] = 1
            if i % prime[j] == 0:
                break
            j += 1


init()

for i in range(len(prime) - 1):
    num = prime[i] + prime[i + 1] + 1
    if num > N:
        break
    if st[num] == 0:
        vis[num] = 1

# print(st)

for i in range(1, N):
    vis[i] += vis[i - 1]

for _ in range(int(input())):
    n, k = read()
    # print(vis[n])
    print("YES" if vis[n] >= k else "NO")