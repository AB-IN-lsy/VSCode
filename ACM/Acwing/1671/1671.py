'''
Author: NEFU AB-IN
Date: 2022-03-22 10:52:15
FilePath: \ACM\Acwing\1671.py
LastEditTime: 2022-03-22 10:54:42
'''
n = int(input())

a = []
for i in range(n):
    x, y = map(int, input().split())
    a.append([x, y])

ans = 0

for x in range(n):
    for y in range(n):
        for z in range(n):
            if x == y or x == z or y == z:
                continue
            x1, y1 = a[x]
            x2, y2 = a[y]
            x3, y3 = a[z]
            if x1 == x2 and y2 == y3:
                ans = max(ans, abs(y2 - y1) * abs(x3 - x2))

print(ans)