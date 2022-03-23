'''
Author: NEFU AB-IN
Date: 2022-03-21 21:36:13
FilePath: \ACM\Acwing\1209.py
LastEditTime: 2022-03-22 16:34:09
'''
path, s = [0] * 10, [0] * 10
st = [0] * 10
p = [0] * 10

ans = 0


def count(l, r):
    return s[r] - s[l - 1] * p[r - l + 1]


def dfs(u):
    global ans
    if u > 9:
        for i in range(1, 10):
            s[i] = s[i - 1] * 10 + path[i]
        for a in range(1, 8):
            if count(1, a) > n:
                return
            for b in range(a + 1, 9):
                x = count(1, a)
                y = count(a + 1, b)
                z = count(b + 1, 9)
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
p[0] = 1
for i in range(1, 10):
    p[i] = p[i - 1] * 10
dfs(1)
print(ans)