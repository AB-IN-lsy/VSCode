'''
Author: NEFU AB-IN
Date: 2022-04-16 20:11:03
FilePath: \ACM\Acwing\1874.py
LastEditTime: 2022-04-16 20:11:03
'''
from collections import Counter

g = []
n, m = map(int, input().split())
for i in range(n):
    g.append(input())

dx = [-1, 0, 1, 0, -1, 1, -1, 1]
dy = [0, 1, 0, -1, 1, 1, -1, -1]

d = Counter()
for i in range(n):
    for j in range(m):
        for k in range(8):
            x1, y1 = i + dx[k], j + dy[k]
            x2, y2 = x1 + dx[k], y1 + dy[k]
            if x2 >= 0 and x2 < n and y2 >= 0 and y2 < m:
                if g[i][j] == 'M' or g[x1][y1] == 'O' or g[x2][y2] == 'O':
                    continue
                if g[i][j] != g[x1][y1] and g[x1][y1] == g[x2][y2]:
                    s = g[i][j] + g[x1][y1] * 2
                    d[s] += 1
ans = 0
for key in d.keys():
    ans = max(ans, d[key])
print(ans)