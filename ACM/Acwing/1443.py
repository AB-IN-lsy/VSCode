'''
Author: NEFU AB-IN
Date: 2022-02-15 13:47:36
FilePath: \ACM\Acwing\1443.py
LastEditTime: 2022-02-15 14:02:49
'''
from collections import Counter

b = []

if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))
    for i in range(1, a[0]):
        d = Counter()  #记录是否重复
        tmp = []  #被记录的字典序

        tmp.append(i)
        d[i] += 1
        t = i  #记录原数组的数
        flag = 0  #判断是否重复
        for j in range(n - 1):
            if d[a[j] - t] or a[j] - t <= 0:
                flag = 1
                break
            d[a[j] - t] = 1
            tmp.append(a[j] - t)
            t = a[j] - t
        if flag == 0:
            b.append(tmp)
    b.sort()
    for i in b[0]:
        print(i, end=" ")
