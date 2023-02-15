'''
Author: NEFU AB-IN
Date: 2022-02-12 14:10:48
FilePath: \ACM\Acwing\1471.1.py
LastEditTime: 2022-02-12 14:17:58
'''
N = 155
g = [[0 for _ in range(N)] for _ in range(N)]

if __name__ == "__main__":
    n = int(input())
    for i in range(n - 1):
        x, y = map(int, input().split())
        g[x][y] = 1
    for i in range(1, n + 1):
        g[i][i] = 1
    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if g[i][k] and g[k][j]:
                    g[i][j] = 1
    for i in range(1, n + 1):
        cnt = 0
        for j in range(1, n + 1):
            if g[j][i]:
                cnt += 1
        if cnt == n:
            print(i)
            exit(0)
    print(-1)