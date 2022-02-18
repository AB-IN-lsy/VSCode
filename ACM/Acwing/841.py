'''
Author: NEFU AB-IN
Date: 2022-02-12 16:07:23
FilePath: \ACM\Acwing\841.py
LastEditTime: 2022-02-12 16:12:41
'''

N = int(1e5 + 100)
P, MOD = 131, 1 << 64

h = [0] * N
p = [0] * N

p[0] = 1


def get(l, r):
    return (h[r] - h[l - 1] * p[r - l + 1]) % MOD


if __name__ == "__main__":
    n, m = map(int, input().split())
    s = input()

    s = " " + s

    for i in range(1, n + 1):
        p[i] = p[i - 1] * P % MOD
        h[i] = (h[i - 1] * P + ord(s[i])) % MOD

    for i in range(m):
        l1, r1, l2, r2 = map(int, input().split())

        if get(l1, r1) == get(l2, r2):
            print("Yes")
        else:
            print("No")
