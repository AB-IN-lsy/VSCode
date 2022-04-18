'''
Author: NEFU AB-IN
Date: 2022-04-12 16:51:34
FilePath: \ACM\Acwing\1824.py
LastEditTime: 2022-04-12 16:51:35
'''
from collections import Counter

d = Counter()
INF = 10010
n, k = map(int, input().split())

mn, mx = INF, -INF
for i in range(n):
    x = int(input())
    d[x] += 1
    mn = min(mn, x)
    mx = max(mx, x)

ans, cnt = 1, 0
for i in range(mn, mx + 1):
    cnt += d[i]
    cnt -= d[i - k - 1]
    ans = max(ans, cnt)

print(ans)