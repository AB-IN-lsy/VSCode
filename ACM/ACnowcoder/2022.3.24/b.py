'''
Author: NEFU AB-IN
Date: 2022-03-04 19:01:45
FilePath: \ACM\ACnowcoder\2022.3.24\b.py
LastEditTime: 2022-03-04 19:01:46
'''

ans = 0


def dfs(cnt):
    global ans
    for i in range(1, cnt + 1):
        ans += 1
    if ans < 100:
        print(ans)
    else:
        return False
    dfs(cnt + 2)


dfs(1)