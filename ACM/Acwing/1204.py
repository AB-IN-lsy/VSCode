'''
Author: NEFU AB-IN
Date: 2022-03-24 19:34:25
FilePath: \ACM\Acwing\1204.py
LastEditTime: 2022-03-24 19:41:29
'''
from collections import Counter

n = int(input())
s = set()
d = Counter()
for i in range(n):
    a = list(map(int, input().split()))
    d.update(a)
    s.update(a)

s = list(s)
s.sort()

for i in range(len(s) - 1):
    if s[i] + 1 != s[i + 1]:
        print(s[i] + 1, end=" ")
        break

for key in d.keys():
    if d[key] == 2:
        print(key)
        break