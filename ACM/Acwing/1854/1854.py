'''
Author: NEFU AB-IN
Date: 2022-04-08 22:34:22
FilePath: \ACM\Acwing\1854.py
LastEditTime: 2022-04-08 22:34:23
'''
a = [0] * 10
b = [0] * 10
c = [0] * 10

for i in range(1, 5):
    a[i], b[i] = map(int, input().split())

for i in range(2, 5):
    x = b[i] - a[i]
    c[1] += x
    c[i + 1] -= x

for i in range(2, 5):
    c[i] += c[i - 1]
    print(c[i])
