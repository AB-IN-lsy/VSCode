'''
Author: NEFU AB-IN
Date: 2022-04-12 16:58:16
FilePath: \ACM\Acwing\1824.1.py
LastEditTime: 2022-04-12 17:03:28
'''
a = []
n, k = map(int, input().split())
for i in range(n):
    a.append(int(input()))

a.sort()

ans = 0
j = 0
for i in range(n):
    while j < n and a[i] - a[j] > k:
        j += 1
    ans = max(ans, i - j + 1)

print(ans)