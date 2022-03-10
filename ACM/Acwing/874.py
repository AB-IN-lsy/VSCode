'''
Author: NEFU AB-IN
Date: 2022-03-10 20:28:12
FilePath: \ACM\Acwing\874.py
LastEditTime: 2022-03-10 20:28:13
'''
N = int(1e6 + 10)
st, phi, prime = [0] * N, [0] * N, [0] * N


def init(n):
    res, cnt = 0, 0
    phi[1] = 1
    for i in range(2, n + 1):
        if st[i] == 0:
            prime[cnt] = i
            phi[i] = i - 1
            cnt += 1
        j = 0
        while i <= n // prime[j]:
            st[i * prime[j]] = 1
            if i % prime[j] == 0:
                phi[i * prime[j]] = phi[i] * prime[j]
                break
            phi[i * prime[j]] = phi[i] * (prime[j] - 1)
            j += 1
    for i in range(1, n + 1):
        res += phi[i]
    print(res)


n = int(input())
init(n)