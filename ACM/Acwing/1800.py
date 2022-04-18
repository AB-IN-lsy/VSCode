'''
Author: NEFU AB-IN
Date: 2022-04-04 21:56:57
FilePath: \ACM\Acwing\1800.py
LastEditTime: 2022-04-04 21:59:03
'''
from collections import Counter

INF = int(2e9)
d = Counter()
n = int(input())
for i in range(n):
    s, x = input().split()
    d[s] += int(x)

minn = INF
for key in d.keys():
    minn = min(minn, d[key])

ans = INF
cnt = 0
for key in d.keys():
    if d[key] > minn and ans >= d[key]:
        if ans == d[key]:
            cnt += 1
        else:
            cnt = 1
        ans = d[key]
        res = key

if ans == INF or cnt > 1:
    print("Tie")
else:
    print(res)