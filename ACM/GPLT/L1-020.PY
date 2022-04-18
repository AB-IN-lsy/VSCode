'''
Author: NEFU AB-IN
Date: 2022-04-15 15:02:56
FilePath: \ACM\GPLT\L1-020.PY
LastEditTime: 2022-04-15 15:02:56
'''
from collections import Counter

st = Counter()
d = Counter()
n = int(input())
for i in range(n):
    s = input().split()[1:]
    if len(s) == 1:
        continue
    d.update(s)

m = int(input())
a = list(input().split())

b = []
for i in range(m):
    if not st[a[i]] and not d[a[i]]:
        b.append(a[i])
        st[a[i]] = 1

flag = 0
for i in range(len(b)):
    if not d[b[i]]:
        print(b[i], end=" " if i < len(b) - 1 else "")
        flag = 1

if not flag:
    print("No one is handsome")