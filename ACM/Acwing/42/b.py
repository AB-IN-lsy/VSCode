'''
Author: NEFU AB-IN
Date: 2022-03-12 18:59:53
FilePath: \ACM\Acwing\42\b.py
LastEditTime: 2022-03-12 19:13:46
'''
n, m, q = map(int, input().split())
s = " " + input()
t = " " + input()

N = 2000
ne = [0] * N

j = 0
for i in range(2, m + 1):
    while j and t[i] != t[j + 1]:
        j = ne[j]
    if t[i] == t[j + 1]:
        j += 1
    ne[i] = j
for _ in range(q):
    l, r = map(int, input().split())
    j, ans = 0, 0
    for i in range(l, r + 1):
        while j and s[i] != t[j + 1]:
            j = ne[j]
        if s[i] == t[j + 1]:
            j += 1
        if j == m:
            ans += 1
            j = ne[j]
    print(ans)