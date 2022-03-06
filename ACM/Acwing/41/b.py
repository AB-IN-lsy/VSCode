'''
Author: NEFU AB-IN
Date: 2022-03-05 19:07:41
FilePath: \ACM\Acwing\41周赛\b.py
LastEditTime: 2022-03-05 19:25:24
'''

s = list()

n, x0, y0 = map(int, input().split())
for i in range(n):
    x, y = map(int, input().split())
    if x == x0:
        s.append(int(2e9))
    else:
        s.append((y - y0) / (x - x0))

res = 1
s.sort()
for i in range(1, len(s)):
    if s[i] - s[i - 1] > 1e-8:
        res += 1

print(res)