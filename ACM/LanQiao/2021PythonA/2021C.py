'''
Author: NEFU AB-IN
Date: 2022-01-11 21:07:15
FilePath: \ACM\LanQiao\2021C.py
LastEditTime: 2022-03-16 11:08:01
'''
import sys

sys.setrecursionlimit(int(2e9))

n = 2021041820210418
a = []
ans = 0


def dfs(id, prob):
    global ans
    if id == 3:
        if prob == n:
            ans += 1
        return
    for i in range(len(a)):
        if prob * a[i] > n:
            return
        dfs(id + 1, prob * a[i])
    return


i = 1
while i <= n // i:
    if n % i == 0:
        a.append(i)
        if i != n // i:
            a.append(n // i)
    i += 1
a.sort()

dfs(0, 1)

print(ans)