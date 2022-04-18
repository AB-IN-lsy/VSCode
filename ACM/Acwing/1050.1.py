'''
Author: NEFU AB-IN
Date: 2022-04-02 16:07:09
FilePath: \ACM\Acwing\1050.1.py
LastEditTime: 2022-04-02 16:17:04
'''
for _ in range(int(input())):
    m, n = map(int, input().split())
    f = [[0] * 15 for _ in range(15)]
    f[0][0] = 1
    for i in range(0, m + 1):
        for j in range(1, n + 1):
            f[i][j] = f[i][j - 1] + f[i - j][j]
    print(f[m][n])