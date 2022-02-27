'''
Author: NEFU AB-IN
Date: 2022-02-27 16:35:09
FilePath: \ACM\Acwing\135.py
LastEditTime: 2022-02-27 16:46:28
'''

from collections import deque

N = int(3e5 + 100)
INF = int(2e9)
a = [0] * N

if __name__ == "__main__":
    n, m = map(int, input().split())
    a[1:] = list(map(int, input().split()))
    q = deque()
    res = -INF
    for i in range(1, n + 1):
        a[i] += a[i - 1]
    q.append(0)  # 左端点初始值为0
    for i in range(1, n + 1):  #枚举右端点
        while q and i - q[0] > m:
            q.popleft()
        res = max(res, a[i] - a[q[0]])
        while q and a[q[-1]] >= a[i]:
            q.pop()
        q.append(i)
    print(res)
