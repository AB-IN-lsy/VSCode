'''
Author: NEFU AB-IN
Date: 2022-02-27 19:10:12
FilePath: \ACM\AtCoder\arc084b.py
LastEditTime: 2022-02-27 19:35:39
'''

from collections import deque

N = int(1e6 + 10)
INF = int(2e9)
dist, st = [INF] * N, [0] * N
q = deque()


def bfs(n):
    q.append(1)
    dist[1] = 1

    while q:
        t = q.popleft()
        if st[t]:
            continue
        st[t] = 1
        if t % n == 0:
            return dist[0]
        if dist[(t + 1) % n] > dist[t] + 1:
            dist[(t + 1) % n] = dist[t] + 1
            q.append((t + 1) % n)
        if dist[(t * 10) % n] > dist[t]:
            dist[(t * 10) % n] = dist[t]
            q.appendleft((t * 10) % n)


if __name__ == "__main__":
    n = int(input())
    print(bfs(n))