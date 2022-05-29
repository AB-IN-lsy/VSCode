'''
Author: NEFU AB-IN
Date: 2021-11-05 19:37:21
FilePath: \ACM\tempCodeRunnerFile.py
LastEditTime: 2022-05-27 19:53:29
'''

N = 20
st, path = [0] * N, [0] * N


def dfs(x):
    if x == n + 1:
        for i in range(1, n + 1):
            print(path[i], end=" ")
        print()
        return
    for i in range(1, n + 1): # 
        if st[i] == 0:
            path[x] = i
            st[i] = 1
            dfs(x + 1)
            st[i] = 0


n = int(input())
a = [i for i in range(n + 1)]

dfs(1)