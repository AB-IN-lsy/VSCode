'''
Author: NEFU AB-IN
Date: 2022-02-07 17:56:46
FilePath: \ACM\Acwing\1762.py
LastEditTime: 2022-02-08 01:04:32
'''
from copy import deepcopy

N = 105
a = []  #标准
b = []  #序列
c = [0 for _ in range(N)]  #反标准

if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))
    b = list(input().split())

    #反映射
    for i in range(n):
        c[a[i] - 1] = i

    for i in range(3):
        t = deepcopy(b)  #新序列
        for j in range(n):
            t[c[j]] = b[j]
        b = deepcopy(t)

    for i in range(n):
        print(b[i])
