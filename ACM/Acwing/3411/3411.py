'''
Author: NEFU AB-IN
Date: 2022-03-17 16:08:06
FilePath: \ACM\Acwing\3411.py
LastEditTime: 2022-03-17 16:09:40
'''
from collections import Counter

n, m, l = map(int, input().split())

d = Counter()

for i in range(n):
    nums = map(int, input().split())
    d.update(nums)

for i in range(l):
    print(d[i], end=" ")
