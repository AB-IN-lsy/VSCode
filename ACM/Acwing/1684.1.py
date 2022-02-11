'''
Author: NEFU AB-IN
Date: 2022-02-10 16:33:26
FilePath: \ACM\Acwing\1684.1.py
LastEditTime: 2022-02-10 16:53:23
'''
from collections import Counter

N = 160
a = [Counter() for _ in range(N)]
b = [Counter() for _ in range(5)]
res = [0 for _ in range(N)]

if __name__ == "__main__":
    n, m = map(int, input().split())
    for i in range(m):
        x, y = map(int, input().split())
        a[x - 1][i] = 1  #第x块地被第i头牛青睐
        a[y - 1][i] = 1
    for i in range(1, 5):  #枚举草的种类
        for j in range(n):  #枚举地
            if res[j]:
                continue
            flag = 0
            for k in a[j].keys():
                if b[i][k]:
                    flag = 1
                    break
            if flag == 0:
                res[j] = i
                for k in a[j].keys():
                    b[i][k] = 1
    for i in range(n):
        print(res[i], end="")
