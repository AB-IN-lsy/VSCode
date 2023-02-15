'''
Author: NEFU AB-IN
Date: 2022-03-10 10:15:25
FilePath: \ACM\Acwing\871.py
LastEditTime: 2022-03-10 10:15:26
'''
from collections import Counter

MOD = int(1e9 + 7)
d = Counter()
for _ in range(int(input())):
    n = int(input())
    i = 2
    while i <= n // i:
        while n % i == 0:
            d[i] += 1
            n //= i
        i += 1
    if n > 1:
        d[n] += 1
ans = 1
for key in d.keys():
    t = 1
    while d[key]:
        d[key] -= 1
        t = (t * key + 1) % MOD
    ans = ans * t % MOD

print(ans)