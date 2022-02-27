'''
Author: NEFU AB-IN
Date: 2022-02-22 11:55:58
FilePath: \ACM\Acwing\795.py
LastEditTime: 2022-02-22 11:58:56
'''

n, m = map(int, input().split())

a = list(map(int, input().split()))
a = [0, *a]

for i in range(1, len(a)):
    a[i] += a[i - 1]

for i in range(m):
    l, r = map(int, input().split())
    print(a[r] - a[l - 1])