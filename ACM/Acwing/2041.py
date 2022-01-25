'''
Author: NEFU AB-IN
Date: 2022-01-16 21:49:26
FilePath: \ACM\Acwing\2041.py
LastEditTime: 2022-01-20 20:44:15
'''

import heapq

N = int(1e6 + 10)
a = [0] * int(N)
b = [0] * int(N)

if __name__ == '__main__':
    n, k = map(int, input().split())
    for i in range(k):
        l, r = map(int, input().split())
        b[l] += 1
        b[r + 1] -= 1
    for i in range(1, n + 1):
        a[i] = a[i - 1] + b[i]

    # print(heapq.nlargest(n // 2 + 1, a[1:n + 1])[-1])

    a[1:n + 1] = sorted(a[1:n + 1])
    print(a[n // 2 + 1])
