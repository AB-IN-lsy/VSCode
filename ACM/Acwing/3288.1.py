'''
Author: NEFU AB-IN
Date: 2022-03-19 13:20:09
FilePath: \ACM\Acwing\3288.1.py
LastEditTime: 2022-03-19 13:49:06
'''


class Node():
    def __init__(self, id, v):
        self.id = id
        self.v = v


n, a, b = map(int, input().split())

A, B = [], []

for i in range(a):
    id, v = map(int, input().split())
    A.append(Node(id, v))
for i in range(b):
    id, v = map(int, input().split())
    B.append(Node(id, v))

j, ans = 0, 0
for i in range(a):
    while j < b and B[j].id < A[i].id:
        j += 1
    if j < b and B[j].id == A[i].id:
        ans += B[j].v * A[i].v
print(ans)