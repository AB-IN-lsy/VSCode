'''
Author: NEFU AB-IN
Date: 2022-03-16 11:49:40
FilePath: \ACM\Acwing\3370.py
LastEditTime: 2022-03-16 14:52:47
'''
from collections import Counter, deque

N = 120
INF = int(2e9)
animals = [
    "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey",
    "Rooster", "Dog", "Pig", "Rat"
]
d, idx = Counter(), Counter()
g = [[] for _ in range(N)]
st, dist = [0] * N, [INF] * N
d['Bessie'] = "Ox"  #记录生效
idx['Bessie'] = 1  #记录编号
cnt = 1


def find(u, v, judge):
    u1 = animals.index(d[u])
    v1 = animals.index(d[v])
    if judge == 'previous':
        if u1 > v1:
            return v1 - (u1 - 12)
        else:
            return v1 - u1 if v1 != u1 else 12

    else:
        if u1 < v1:
            return -(u1 + 12 - v1)
        else:
            return u1 - v1 if v1 != u1 else -12


def spfa():
    q = deque()
    st[1] = 1
    q.appendleft(1)
    dist[1] = 0
    while q:
        u = q.pop()
        st[u] = 0
        for v, w in g[u]:
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                if st[v] == 0:
                    st[v] = 1
                    q.appendleft(v)
    return dist[idx['Elsie']]


n = int(input())
for i in range(n):
    sentence = input().split()
    u, judge, animal, v = sentence[0], sentence[3], sentence[4], sentence[-1]
    d[u] = animal
    cnt += 1
    idx[u] = cnt
    w = find(u, v, judge)
    g[idx[u]].append([idx[v], w])
    g[idx[v]].append([idx[u], -w])

print(abs(spfa()))