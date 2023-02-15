'''
Author: NEFU AB-IN
Date: 2022-03-30 15:56:43
FilePath: \ACM\Acwing\112.py
LastEditTime: 2022-03-30 15:56:43
'''
n, d = map(int, input().split())
pos = []
for i in range(n):
    pos.append(tuple(map(int, input().split())))

a = []
for x, y in pos:
    if y > d:
        print(-1)
        exit(0)
    D = pow(d * d - y * y, 0.5)
    a.append([x - D, x + D])

a.sort(key=lambda x: x[1])
R = -int(2e9)
ans = 0
for l, r in a:
    if l > R:
        ans += 1
        R = r

print(ans)