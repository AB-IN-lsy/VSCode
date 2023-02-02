'''
Author: NEFU AB-IN
Date: 2023-01-28 19:01:44
FilePath: \Acwing\88cp\a.py
LastEditTime: 2023-01-28 19:03:16
'''
from collections import Counter


def check(x):
    d = Counter(str(x))
    for key in d.keys():
        if d[key] > 1:
            return 0
    return 1


x = int(input())

for i in range(x + 1, 100000):
    if check(i):
        print(i)
        exit(0)