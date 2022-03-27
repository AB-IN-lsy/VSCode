'''
Author: NEFU AB-IN
Date: 2022-03-26 18:54:01
FilePath: \ACM\Acwing\44\b.py
LastEditTime: 2022-03-27 19:51:54
'''
from collections import Counter, deque

N = 550
B = N // 2
g = [[0] * N for _ in range(N)]
s = input()
d = Counter(s)

if d['L'] == d['R'] and d['U'] == d['D']:  #判断是否起点终点相同
    print("NO")
    exit(0)

x1, y1 = B, B  #起点
g[x1][y1] = 1

#判断是否有环
for i in s:
    if i == 'L': x1 -= 1
    if i == 'R': x1 += 1
    if i == 'U': y1 += 1
    if i == 'D': y1 -= 1
    if g[x1][y1]:
        print("NO")
        exit(0)
    g[x1][y1] = 1

#BFS
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
q = deque()
q.appendleft([B, B, 0])
while q:
    x, y, cnt = q.pop()
    if x == x1 and y == y1:
        break
    for i in range(4):
        x2 = x + dx[i]
        y2 = y + dy[i]
        if g[x2][y2] == 1:
            q.appendleft([x2, y2, cnt + 1])
            g[x2][y2] = 0

if cnt != len(s):
    print("NO")
    exit(0)

print("YES")
