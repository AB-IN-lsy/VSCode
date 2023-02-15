'''
Author: NEFU AB-IN
Date: 2022-01-19 19:13:13
FilePath: \ACM\Acwing\1922.py
LastEditTime: 2022-01-19 19:26:07
'''
N = int(1e6 + 10)
b = [0] * N
a = [0] * N

if __name__ == "__main__":
    n, k = map(int, input().split())
    for _ in range(n):
        g, x = map(int, input().split())
        a[max(0, x - k)] += g
        a[min(x + k + 1, int(1e6))] -= g
    res = 0
    for i in range(N):
        b[i] = b[max(0, i - 1)] + a[i]
        res = max(res, b[i])
    print(res)
