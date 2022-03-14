'''
Author: NEFU AB-IN
Date: 2022-03-14 20:50:31
FilePath: \ACM\Acwing\908.py
LastEditTime: 2022-03-14 20:50:31
'''
n = int(input())
INF = int(2e9)

r = -INF

a = []
for i in range(n):
    L, R = map(int, input().split())
    a.append([L, R])

a.sort(lambda x: x[1])

ans = 0
for L, R in a:
    if L > r:
        ans += 1
        r = R

print(ans)