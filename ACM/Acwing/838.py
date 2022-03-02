'''
Author: NEFU AB-IN
Date: 2022-03-02 10:37:05
FilePath: \ACM\Acwing\838.py
LastEditTime: 2022-03-02 10:43:56
'''
import heapq

n, m = map(int, input().split())

a = list(map(int, input().split()))
q = []

for i in range(n):
    heapq.heappush(q, a[i])

for i in range(m):
    print(heapq.heappop(q), end=" ")
