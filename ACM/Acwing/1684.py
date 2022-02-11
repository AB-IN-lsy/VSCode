'''
Author: NEFU AB-IN
Date: 2022-02-10 15:55:47
FilePath: \ACM\Acwing\1684.py
LastEditTime: 2022-02-10 16:30:00
'''

from collections import Counter

N = 160
a = [Counter() for _ in range(N)]
res = [0 for _ in range(N)]

if __name__ == "__main__":
    n, m = map(int, input().split())
    for i in range(m):
        x, y = map(int, input().split())
        a[x - 1][i] = 1  #第x块地被第i头牛青睐
        a[y - 1][i] = 1
    # print(a)
    tot = 1
    for i in range(n):  #枚举地
        if res[i] == 0:  #未分配则分配
            res[i] = tot
            tot += 1
        else:  #分配了就过
            continue
        for ii in range(i + 1, n):  #枚举其他地
            if res[ii]:  #分配了就过
                continue
            flag = 0
            for j in a[i].keys():  #枚举每个地的牛，看两个地有无交集
                if flag:
                    break
                for jj in a[ii].keys():  #枚举每个地的牛
                    if a[ii][j]:
                        flag = 1
                        break
            if flag == 0:  #无交集的话，就让ii地和i地一个种类
                res[ii] = res[i]
                for jj in a[ii].keys():  #并更新此种类
                    a[i][jj] = 1
    for i in range(n):
        print(res[i], end="")
