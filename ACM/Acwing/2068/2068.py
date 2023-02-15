'''
Author: NEFU AB-IN
Date: 2022-04-07 19:15:23
FilePath: \ACM\Acwing\2068.py
LastEditTime: 2022-04-07 19:22:52
'''
from math import log10
from collections import Counter

d = [Counter() for _ in range(11)]

n, k = map(int, input().split())
a = list(map(int, input().split()))
ans = 0
#正序
for i in a:
    for j in range(11):
        ans += d[j][(k - (i * (10**j) % k)) % k]
    d[int(log10(i) + 1)][i % k] += 1
#逆序
a = a[::-1]
d = [Counter() for _ in range(11)]
for i in a:
    for j in range(11):
        ans += d[j][(k - (i * (10**j) % k)) % k]
    d[int(log10(i) + 1)][i % k] += 1
print(ans)
