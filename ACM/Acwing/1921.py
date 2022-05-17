'''
Author: NEFU AB-IN
Date: 2022-05-15 22:07:30
FilePath: \ACM\Acwing\1921.py
LastEditTime: 2022-05-16 08:11:24
'''

n = int(input())

a = [0]
b = [0]
idx = [0] * (n + 1)

for i in range(1, n + 1):
    a.append(int(input()))
    idx[a[i]] = i

for i in range(1, n + 1):
    b.append(int(input()))

ans = -1
cnt = 0
vis = [0] * (n + 1)
for i in range(1, n + 1):
    id = idx[i]
    tmp = 0
    while True:
        if vis[id]:
            break
        vis[id] = 1
        t = b[id]
        id = idx[t]
        tmp += 1
        if id == idx[i] and tmp > 1:
            cnt += 1
            ans = max(ans, tmp)
            break
print(cnt, ans)