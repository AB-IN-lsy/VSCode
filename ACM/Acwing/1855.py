'''
Author: NEFU AB-IN
Date: 2022-01-25 22:18:56
FilePath: \ACM\Acwing\1855.py
LastEditTime: 2022-01-25 22:44:48
'''
from collections import deque

N = 105
A = []


def bfs(k):
    q = deque()
    vis = [0] * N

    cnt = 1
    q.appendleft([k, cnt])
    # 下标，爆炸范围
    vis[k] = 1
    res = 0
    while len(q):
        tmp = q.pop()
        k = tmp[0]
        cnt = tmp[1]
        res += 1
        for i in range(k):
            if A[i] >= A[k] - cnt and vis[i] == 0:
                q.appendleft([i, cnt + 1])
                vis[i] = 1
        for i in range(k + 1, n):
            if A[i] <= A[k] + cnt and vis[i] == 0:
                q.appendleft([i, cnt + 1])
                vis[i] = 1
    return res


if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        A.append(int(input()))
    A.sort()

    res = 0
    for i in range(n):
        res = max(res, bfs(i))
    print(res)
