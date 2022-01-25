'''
Author: NEFU AB-IN
Date: 2022-01-21 22:05:18
FilePath: \ACM\Acwing\1922.2.py
LastEditTime: 2022-01-21 22:24:50
'''

N = int(1e6 + 10)
lst = [0] * N

if __name__ == "__main__":
    n, k = map(int, input().split())
    maxn = 0
    for _ in range(n):
        g, x = map(int, input().split())
        # 因x能取到0，所以将x加一
        lst[x + 1] = g
    for i in range(1, N):
        lst[i] += lst[i - 1]
    res = 0
    for i in range(N):
        l = max(1, i - k)
        r = min(i + k, N - 1)
        res = max(res, lst[r] - lst[l - 1])
    print(res)
