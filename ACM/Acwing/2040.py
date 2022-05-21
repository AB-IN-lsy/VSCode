'''
Author: NEFU AB-IN
Date: 2022-05-21 14:12:03
FilePath: \ACM\Acwing\2040.py
LastEditTime: 2022-05-21 14:15:55
'''
n, b = map(int, input().split())

a = []
for i in range(n):
    p, s = map(int, input().split())
    a.append([p, s])

a.sort(key=lambda x: [x[0] + x[1], x[0]])

maxn = 0
for i in range(n):
    cnt = 1
    ans = a[i][0] / 2 + a[i][1]
    if ans > b:
        continue
    maxn = max(maxn, cnt)
    for j in range(n):
        if i == j:
            continue
        ans += a[j][0] + a[j][1]
        if ans > b:
            break
        cnt += 1
        maxn = max(maxn, cnt)
print(maxn)