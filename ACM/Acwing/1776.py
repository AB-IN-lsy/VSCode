'''
Author: NEFU AB-IN
Date: 2022-02-05 17:35:56
FilePath: \ACM\Acwing\1776.py
LastEditTime: 2022-02-05 17:52:18
'''

from collections import defaultdict

a = []  #不正常
b = []  #正常

if __name__ == "__main__":
    n, m = map(int, input().split())
    for i in range(n):
        a.append(input())
    for i in range(n):
        b.append(input())
    res = 0
    for i in range(m):
        d = defaultdict(int)
        for j in range(n):
            d[a[j][i]] += 1
        flag = 0
        for j in range(n):
            if d[b[j][i]]:
                flag = 1
                break
        if not flag:
            res += 1
    print(res)