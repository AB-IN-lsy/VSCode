'''
Author: NEFU AB-IN
Date: 2022-03-23 17:01:00
FilePath: \ACM\Acwing\1659.py
LastEditTime: 2022-03-23 21:10:19
'''
N = int(1e5 + 10)
nxt = [0] * N
INF = int(2e9)


def check(x):
    cnt = 0
    i, id = 0, -INF
    while i < n:
        if a[i] == 0 and i - id >= x and nxt[i] - i >= x:
            cnt += 1
            id = i
        if a[i] == 1:
            id = i
        i += 1
    return cnt >= 2


n = int(input())
a = list(map(int, input()))

#求next数组，即0的下一个1在哪
id = INF
for i in range(n - 1, -1, -1):
    if a[i] == 0:
        nxt[i] = id
    else:
        id = i

#求1之间的最小距离，也就是二分上界
id = -INF
r = n - 1
for i in range(n):
    if a[i] == 1:
        if id != -INF:
            r = min(r, i - id)
        id = i
# 二分D
l = 1
while l < r:
    mid = l + r + 1 >> 1
    if check(mid):
        l = mid
    else:
        r = mid - 1
print(r)