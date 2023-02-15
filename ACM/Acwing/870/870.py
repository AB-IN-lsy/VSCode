'''
Author: NEFU AB-IN
Date: 2022-03-09 21:40:15
FilePath: \ACM\Acwing\870.py
LastEditTime: 2022-03-09 21:40:16
'''
MOD = int(1e9 + 7)
from collections import Counter

d = Counter()
for _ in range(int(input())):
    n = int(input())
    i = 2
    while i <= n // i:
        while n % i == 0:
            n //= i
            d[i] += 1
        i += 1
    if n > 1:
        d[n] += 1
ans = 1
for key in d.keys():
    ans = ans * (d[key] + 1) % MOD
print(ans)