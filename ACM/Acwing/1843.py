'''
Author: NEFU AB-IN
Date: 2022-01-26 13:16:29
FilePath: \ACM\Acwing\1843.py
LastEditTime: 2022-01-27 22:57:34
'''

A = []
INF = int(4e9)

if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        A.append(int(input()))
    sum = sum(A)
    res = INF
    for i in range(n):
        tmp = (n - 1) * sum
        k = (n - 1)
        for j in range(i, n):
            tmp -= (k * A[j])
            k -= 1
        for j in range(0, i - 1):
            tmp -= (k * A[j])
            k -= 1
        res = min(res, tmp)
    print(res)
