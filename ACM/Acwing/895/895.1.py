'''
Author: NEFU AB-IN
Date: 2022-03-23 19:20:33
FilePath: \ACM\Acwing\895.1.py
LastEditTime: 2022-03-23 19:21:43
'''
from bisect import bisect_left

n = int(input())

a = list(map(int, input().split()))
stk = []

for i in range(n):
    idx = bisect_left(stk, a[i])
    if idx == len(stk):
        stk.append(a[i])
    else:
        stk[idx] = a[i]

print(len(stk))