'''
Author: NEFU AB-IN
Date: 2022-04-02 15:50:49
FilePath: \ACM\Acwing\1050.py
LastEditTime: 2022-04-02 15:50:49
'''
for _ in range(int(input())):
    m, n = map(int, input().split())
    f = [0] * 15
    f[0] = 1
    for i in range(1, n + 1):
        for j in range(i, m + 1):
            f[j] += f[j - i]
    print(f[m])