'''
Author: NEFU AB-IN
Date: 2022-03-15 17:42:15
FilePath: \ACM\Acwing\125.py
LastEditTime: 2022-03-15 17:52:45
'''

import copy


class COW(object):
    def __init__(self, w=0, s=0):
        self.w = w
        self.s = s
        self.prob = 0


N = int(5e4 + 10)

n = int(input())
cow = [COW() for _ in range(n)]

for i in range(n):
    cow[i].w, cow[i].s = map(int, input().split())
    cow[i].prob = cow[i].s * cow[i].w

cow.sort(key=lambda x: x.prob)

weight = 0
ans = 0
for i in range(n):
    if weight > cow[i].s:
        ans += (weight - cow[i].s)
    weight += cow[i].w

print(ans)