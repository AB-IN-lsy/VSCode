'''
Author: NEFU AB-IN
Date: 2022-04-16 18:57:57
FilePath: \ACM\Acwing\47\b.py
LastEditTime: 2022-04-16 19:27:29
'''
n, k = map(int, input().split())
a = list(map(int, input().split()))
q = [i for i in range(n)]

s = 0
for i in range(k):
    id = (s + a[i]) % len(q)
    s = (id + 1) % len(q)
    print(q[id] + 1, end=" ")
    q.pop(id)
    if s:
        s = (s - 1) % len(q)
