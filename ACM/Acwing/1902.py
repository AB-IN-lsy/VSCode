'''
Author: NEFU AB-IN
Date: 2022-04-13 10:56:49
FilePath: \ACM\Acwing\1902.py
LastEditTime: 2022-04-13 10:56:50
'''


def cale(p, q):
    return abs(p[0] - q[0]) + abs(p[1] - q[1])


n = int(input())

a = []  #原数组
b = []  #间隔数组
c = []  #去除的间隔数组

for i in range(n):
    x, y = map(int, input().split())
    a.append([x, y])

for i in range(1, n):
    b.append(cale(a[i], a[i - 1]))

for i in range(2, n):
    c.append(cale(a[i], a[i - 2]))

ans, cnt, tmp = sum(b), sum(b), sum(b)
for i in range(len(c)):
    cnt -= (b[i] + b[i + 1])
    cnt += c[i]
    ans = min(ans, cnt)
    cnt = tmp

print(ans)
