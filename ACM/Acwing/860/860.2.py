'''
Author: NEFU AB-IN
Date: 2022-03-04 22:54:08
FilePath: \ACM\Acwing\860.2.py
LastEditTime: 2022-03-04 22:54:26
'''
from collections import defaultdict
from collections import deque
import sys

if __name__ == '__main__':

    n, m = map(int, input().split())
    graph = defaultdict(list)

    def add_edge(a, b):
        graph[a].append(b)
        graph[b].append(a)

    for _ in range(m):
        line = list(sys.stdin.readline().strip().split())
        a, b = map(int, line)
        add_edge(a, b)

    color = [-1 for i in range(n + 1)]

    def bfs(i, c):
        queue = deque()
        queue.append(i)
        color[i] = c
        while queue:
            i = queue.popleft()
            c = color[i]
            for j in graph[i]:
                if color[j] == -1:
                    color[j] = (not c)
                    queue.append(j)
                elif color[j] == c:
                    return False
        return True

    flag = True
    for i in range(1, n + 1):
        if color[i] == -1:
            if not bfs(i, 0):
                flag = False
                break

    if flag:
        print('Yes')
    else:
        print('No')