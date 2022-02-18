'''
Author: NEFU AB-IN
Date: 2022-02-15 16:16:56
FilePath: \ACM\Acwing\100.py
LastEditTime: 2022-02-15 17:12:00
'''
N = int(1e5 + 100)
a = [0] * N
b = [0] * N

if __name__ == "__main__":
    n = int(input())
    neg = 0
    pos = 0
    for i in range(1, n + 1):
        a[i] = int(input())
    for i in range(2, n + 1):
        if a[i] - a[i - 1] > 0:
            pos += (a[i] - a[i - 1])
        else:
            neg -= (a[i] - a[i - 1])
    print(min(pos, neg) + abs(pos - neg))
    print(abs(pos - neg) + 1)