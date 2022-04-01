'''
Author: NEFU AB-IN
Date: 2022-04-01 14:53:40
FilePath: \ACM\Acwing\1296.py
LastEditTime: 2022-04-01 14:56:07
'''
from copy import deepcopy
from collections import defaultdict

N = int(1e6 + 10)
st, primes = [0] * N, []
d = defaultdict(list)


def init():
    for i in range(2, N):
        if st[i] == 0:
            primes.append(i)
        j = 0
        while primes[j] * i < N:
            st[primes[j] * i] = 1
            if i % primes[j] == 0:
                break
            j += 1


def check(x):
    if x < N:
        return not st[x]
    i = 0
    while primes[i] <= x // primes[i]:
        if x % primes[i] == 0:
            return 0
        i += 1
    return 1


def dfs(last, prod, s):
    if s == 1:
        ans.append(prod)
        return
    if s - 1 > (1 if last < 0 else primes[last]) and check(s - 1):
        ans.append(prod * (s - 1))
    i = last + 1
    while primes[i] <= s // primes[i]:
        p = primes[i]
        j = 1 + p
        t = p
        while j <= s:
            if s % j == 0:
                dfs(i, prod * t, s // j)
            t *= p
            j += t
        i += 1


init()

while True:
    try:
        n = int(input())
        ans = []

        if d[n] != []:
            print(len(d[n]))
            if len(d[n]):
                d[n].sort()
                for i in d[n]:
                    print(i, end=" ")
                print()
            continue

        dfs(-1, 1, n)

        d[n] = deepcopy(ans)

        print(len(ans))
        if len(ans):
            ans.sort()
            for i in ans:
                print(i, end=" ")
            print()
    except:
        break
