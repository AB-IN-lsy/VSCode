'''
Author: NEFU AB-IN
Date: 2022-02-28 20:22:41
FilePath: \ACM\Acwing\831.1.py
LastEditTime: 2022-02-28 22:19:15
'''

N = int(1e5 + 10)
M = int(1e6 + 10)
ne = [0] * N

n = int(input())
p = input()
p = " " + p

m = int(input())
s = input()
s = " " + s

j = 0
for i in range(2, n + 1):
    while j and p[i] != p[j + 1]:
        j = ne[j]
    if p[i] == p[j + 1]:
        j += 1
    ne[i] = j

j = 0
for i in range(1, m + 1):
    while j and s[i] != p[j + 1]:
        j = ne[j]
    if s[i] == p[j + 1]:
        j += 1
    if j == n:
        print(i - n, end=" ")
        j = ne[j]

lyr
wyp
my
lsy
