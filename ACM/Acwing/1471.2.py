'''
Author: NEFU AB-IN
Date: 2022-02-12 14:36:01
FilePath: \ACM\Acwing\1471.2.py
LastEditTime: 2022-02-12 14:38:12
'''

N = 155
deg = [0] * N

if __name__ == "__main__":
    n = int(input())

    for i in range(n - 1):
        x, y = map(int, input().split())
        deg[x] += 1

    cnt = 0
    res = 0
    for i in range(1, n + 1):
        if deg[i] == 0:
            cnt += 1
            res = i
    if cnt == 1:
        print(res)
    else:
        print(-1)