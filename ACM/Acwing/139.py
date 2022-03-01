'''
Author: NEFU AB-IN
Date: 2022-02-28 15:59:28
FilePath: \ACM\Acwing\139.py
LastEditTime: 2022-02-28 17:10:42
'''
P, MOD = 131, 1 << 64

N = int(2e6 + 100)
hl, hr, p = [0] * N, [0] * N, [0] * N
p[0] = 1


def get(h, l, r):
    return (h[r] - h[l - 1] * p[r - l + 1] % MOD) % MOD


cnt = 0
while True:
    try:
        cnt += 1
        s = input()
        if s == "END":
            break
        s = list(" " + s)
        n = len(s) - 1
        s = [*s * 2]
        for i in range(2 * n, 0, -2):
            s[i] = s[i // 2]
            s[i - 1] = '#'
        n *= 2

        j = n
        for i in range(1, n + 1):
            hl[i] = (hl[i - 1] * P % MOD + ord(s[i])) % MOD
            hr[i] = (hr[i - 1] * P % MOD + ord(s[j])) % MOD
            p[i] = p[i - 1] * P % MOD
            j -= 1

        res = 0
        print(get(hl, 1, 1), get(hr, n - 1, n - 1))
        for i in range(1, n + 1):
            l, r = 0, min(i - 1, n - i)
            while l < r:
                mid = l + r + 1 >> 1
                if get(hl, i - mid, i - 1) == get(hr, n - (i + mid) + 1,
                                                  n - (i + 1) + 1):
                    l = mid
                else:
                    r = mid - 1
            if s[i - r] == '#':
                res = max(res, r)
            else:
                res = max(res, r + 1)
        print(f"Case {cnt}: {res}")
    except:
        break