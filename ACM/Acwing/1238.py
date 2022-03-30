'''
Author: NEFU AB-IN
Date: 2022-03-28 19:45:51
FilePath: \ACM\Acwing\1238.py
LastEditTime: 2022-03-28 20:07:01
'''
from bisect import bisect_left
from collections import Counter, defaultdict

d = defaultdict(list)
res = Counter()

n, D, k = map(int, input().split())
order = []

for i in range(n):
    ts, id = map(int, input().split())
    order.append([id, ts])

order.sort()

for id, ts in order:
    if res[id]:
        continue
    d[id].append(ts)
    res[id] = (len(d[id]) - bisect_left(d[id], ts - D + 1) >= k)

for key in sorted(res.keys()):
    if res[key]: print(key)