'''
Author: NEFU AB-IN
Date: 2022-03-09 18:48:14
FilePath: \ACM\Acwing\867.py
LastEditTime: 2022-03-09 18:48:15
'''
from collections import Counter

for i in range(int(input())):
    n = int(input())
    d = Counter()
    i = 2
    while i <= n // i:
        while n % i == 0:
            d[i] += 1
            n //= i
        i += 1
    if n > 1:
        d[n] += 1
    for key in d.keys():
        print(key, d[key])
    print()