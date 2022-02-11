'''
Author: NEFU AB-IN
Date: 2022-02-10 11:30:55
FilePath: \ACM\Acwing\1726.py
LastEditTime: 2022-02-10 11:34:15
'''
if __name__ == "__main__":
    n, m, k = map(int, input().split())
    lev = [i - 1 for i in list(map(int, input().split()))]
    hlv = [0] * n
    for i in lev:
        hlv[i] = 1

    v, p = [-1] * n, [-1] * n
    for i in range(k):
        vi, pi = map(int, input().split())
        vi -= 1
        pi -= 1
        p[vi], v[pi] = pi, vi

    if p[0] != -1:
        print(p[0] + 1)

    elif hlv[0]:
        j = 0
        for i in lev:
            if p[i] != -1:
                j = p[i] + 1
                continue

            while v[j] != -1:
                j += 1

            p[i], v[j] = j, i
            if i == 0:
                break

        print(p[0] + 1)

    else:
        j = n - 1
        for i in lev[::-1]:
            if p[i] != -1:
                j = p[i] - 1
                continue

            while v[j] != -1:
                j -= 1

            v[j], p[i] = i, j

        for i in range(n):
            if v[i] == -1:
                print(i + 1)
                break