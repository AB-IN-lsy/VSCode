'''
Author: NEFU AB-IN
Date: 2022-01-18 12:50:31
FilePath: \ACM\Acwing\1934.py
LastEditTime: 2022-02-18 20:30:00
'''
a = []  #时间
b = []  #路程

if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        op, x = input().split()
        x = int(x)
        if op == 'T':
            a.append(x)
        else:
            b.append(x)
    b.append(1000)  #添加终点
    a.sort()
    b.sort()

    t, s, v = 0, 0, 1  #v时速度的倒数
    i, j = 0, 0
    while i < len(a) or j < len(b):
        if j == len(b) or i < len(a) and a[i] - t < (b[j] - s) * v:
            s += (a[i] - t) / v
            t = a[i]
            v += 1
            i += 1
        else:
            t += (b[j] - s) * v
            s = b[j]
            v += 1
            j += 1
    print(round(t))
