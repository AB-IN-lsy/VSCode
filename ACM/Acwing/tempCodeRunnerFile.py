'''
Author: NEFU AB-IN
Date: 2022-03-21 21:36:13
FilePath: \ACM\Acwing\1209.py
LastEditTime: 2022-03-22 11:28:45
'''
path = [0] * 10
st = [0] * 10

ans = 0


def count(l, r):
    res = 0
    for i in range(l, r):
        res = res * 10 + path[i]
    return res


def dfs(u):
    global ans
    if u > 9:
        for a in range(1, 8):
            if count(1, a + 1) > n:
                return
            for b in range(a + 1, 9):
                x = count(1, a + 1)
                y = count(a + 1, b + 1)
                z = count(b + 1, 10)
                if x * z + y == z * n:
                    ans += 1
        return

    for i in range(1, 10):
        if st[i] == 0:
            st[i] = 1
            path[u] = i
            dfs(u + 1)
            st[i] = 0
    return


n = int(input())

dfs(1)
print(ans)