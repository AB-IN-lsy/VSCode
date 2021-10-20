'''
Author: NEFU AB-IN
Date: 2021-10-09 15:49:53
FilePath: \ACM\CF\2021.10.9\a.py
LastEditTime: 2021-10-09 16:07:24
'''
n, k = map(int, input().split())
l = list()
d = dict()
vis = dict()
ll = list()
for i in range(3 * n):
    s = input()
    l.append(s)
    d.setdefault(s, 0)
    vis.setdefault(s, 0)
for i in l:
    d[i] += 1
for i in d.keys():
    if d[i] > 1 and vis[i] == 0:
        ll.append((d[i], i))
        vis[i] = 1
ll.sort(reverse=True)
for i in range(min(k, len(ll))):
    print(ll[i][1])
if len(ll) < k:
    cnt = k - len(ll)
    for i in range(len(l) - 1, -1, -1):
        if vis[l[i]] == 0:
            print(l[i])
            vis[l[i]] = 1
            cnt -= 1
        if cnt <= 0:
            break
