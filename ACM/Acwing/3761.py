'''
Author: NEFU AB-IN
Date: 2022-04-05 19:17:38
FilePath: \ACM\Acwing\3761.py
LastEditTime: 2022-04-05 19:17:45
'''
from collections import Counter

INF = int(1e18)
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    d = Counter(a)

    mp = Counter()
    for i in range(n):
        if d[a[i]] == 1:
            mp[a[i]] = i + 1

    ans = INF
    for key in d.keys():
        if d[key] == 1:
            ans = min(ans, key)
    print(mp[ans] if ans != INF else -1)