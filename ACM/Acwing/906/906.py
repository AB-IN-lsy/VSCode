'''
Author: NEFU AB-IN
Date: 2022-03-14 23:15:56
FilePath: \ACM\Acwing\906.py
LastEditTime: 2022-03-14 23:15:56
'''
N = int(1e5 + 10) * 2

a = []
n = int(input())
idx = 0
for i in range(n):
    l, r = map(int, input().split())
    a.append(l * 2)
    a.append(r * 2 + 1)

a.sort()
res, cnt = 0, 0
for i in range(len(a)):
    if a[i] % 2 == 0:
        cnt += 1
    else:
        cnt -= 1
    res = max(res, cnt)
print(res)
