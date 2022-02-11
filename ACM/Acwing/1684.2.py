'''
Author: NEFU AB-IN
Date: 2022-02-10 17:15:09
FilePath: \ACM\Acwing\1684.2.py
LastEditTime: 2022-02-11 09:23:11
'''
from collections import Counter

N = 160
a = [Counter() for _ in range(N)]  #互斥关系
res = [0 for _ in range(N)]  #表示草地i的草地种类

if __name__ == "__main__":
    n, m = map(int, input().split())
    for i in range(m):
        x, y = map(int, input().split())
        a[x - 1][y - 1] = 1  #读入互斥关系
        a[y - 1][x - 1] = 1
    for i in range(n):  #枚举每个草地
        b = [0 for _ in range(5)]  #表示草地种类是否被用过
        for j in range(n):
            if a[i][j] == 1:  #如果j和i互斥，那么res[j]这个草地种类不能选
                b[res[j]] = 1
        for j in range(1, 5):  #给i放上最小的草地种类即可
            if b[j] == 0:
                res[i] = j
                break
    for i in range(n):
        print(res[i], end="")