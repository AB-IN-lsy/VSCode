'''
Author: NEFU AB-IN
Date: 2022-01-16 00:23:00
FilePath: \ACM\Acwing\tempCodeRunnerFile.py
LastEditTime: 2022-03-01 19:31:16
'''
from collections import deque

N = int(1e6) + 10

n, k = map(int, input().split())
a = list(map(int, input().split()))
q = deque()

for i in range(n):
    while q and i - q[0] + 1 > k:
        q.popleft()
    while q and a[i] <= a[q[-1]]:
        q.pop()
    q.append(i)
    if i >= k - 1:
        print(a[q[0]])
