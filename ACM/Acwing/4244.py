'''
Author: NEFU AB-IN
Date: 2022-02-12 15:03:48
FilePath: \ACM\Acwing\4244.py
LastEditTime: 2022-02-12 15:09:08
'''

N = 155
g = [[0 for _ in range(N)] for _ in range(N)]

if __name__ == "__main__":
    n, m = map(int, input().split())

    for i in range(1, n + 1):
        g[i][i] = 1
    for i in range(m):
        x, y = map(int, input().split())
        g[x][y] = 1

    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if g[i][k] and g[k][j]:
                    g[i][j] = 1

    res = 0
    for i in range(1, n + 1):
        cnt = 0
        for j in range(1, n + 1):
            if g[i][j] or g[j][i]:
                cnt += 1
        if cnt == n:
            res += 1

    print(res)