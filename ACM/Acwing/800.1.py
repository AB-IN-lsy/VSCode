'''
Author: NEFU AB-IN
Date: 2022-01-25 18:45:48
FilePath: \ACM\Acwing\800.1.py
LastEditTime: 2022-01-25 19:07:58
'''
from bisect import bisect_left

if __name__ == "__main__":
    n, m, x = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    for i in range(n):
        j = bisect_left(B, x - A[i])
        if j == m:
            continue
        if A[i] + B[j] == x:
            print(i, j)
            exit(0)