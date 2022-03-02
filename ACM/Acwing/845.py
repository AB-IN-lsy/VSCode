'''
Author: NEFU AB-IN
Date: 2022-03-02 16:49:23
FilePath: \ACM\Acwing\845.py
LastEditTime: 2022-03-02 17:20:48
'''

from collections import Counter, deque

d = Counter()


def bfs(start):
    q = deque()
    q.appendleft(start)
    end = '12345678x'
    while q:
        t = q.pop()
        if t == end:
            return d[t]
        dx = [-1, 0, 1, 0]
        dy = [0, 1, 0, -1]

        id = t.index('x')
        x, y = id // 3, id % 3
        for i in range(4):
            x1 = x + dx[i]
            y1 = y + dy[i]
            tmp = list(t)
            if x1 >= 0 and x1 < 3 and y1 >= 0 and y1 < 3:
                tmp[id], tmp[x1 * 3 + y1] = tmp[x1 * 3 + y1], tmp[id]
                tmp = "".join(tmp)
                if not d[tmp]:
                    q.appendleft(tmp)
                    d[tmp] = d[t] + 1
    return -1


start = "".join(input().split())
print(bfs(start))