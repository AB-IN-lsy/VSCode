'''
Author: NEFU AB-IN
Date: 2022-05-15 21:52:35
FilePath: \ACM\Acwing\1353.py
LastEditTime: 2022-05-15 21:55:45
'''

n = int(input())

a = []
for i in range(n):
    a.append(int(input()))

res = int(1e18)
for i in range(0, 84):
    cost = 0
    for j in range(n):
        if a[j] < i:
            cost += (i - a[j])**2
        elif a[j] > i + 17:
            cost += (a[j] - i - 17)**2
    res = min(res, cost)

print(res)
