'''
Author: NEFU AB-IN
Date: 2022-05-22 11:01:33
FilePath: \ACM\Acwing\3359.py
LastEditTime: 2022-05-22 11:05:32
'''

ans = 0


# 从i开始，组成偶数，第几组
def dfs(i, op, cnt):
    global ans
    if i == n:
        ans = max(ans, cnt)
        return
    b = 0
    while i < n:
        b += a[i]
        if b % 2 == op:
            dfs(i + 1, op ^ 1, cnt + 1)
        i += 1


n = int(input())
a = list(map(int, input().split()))

dfs(0, 0, 0)

print(ans)
