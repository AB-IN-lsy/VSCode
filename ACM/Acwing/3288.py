'''
Author: NEFU AB-IN
Date: 2022-03-18 15:45:29
FilePath: \ACM\Acwing\3288.py
LastEditTime: 2022-03-18 16:23:38
'''
from collections import Counter

A = Counter()
B = Counter()

n, a, b = map(int, input().split())

for i in range(a):
    index, value = map(int, input().split())
    A[index] = value
for i in range(b):
    index, value = map(int, input().split())
    B[index] = value

ans = 0
for index in A.keys():
    if B[index]:
        ans += A[index] * B[index]

print(ans)