'''
Author: NEFU AB-IN
Date: 2022-01-27 20:57:53
FilePath: \ACM\Acwing\1826.py
LastEditTime: 2022-01-27 22:26:47
'''

A = []
INF = int(4e9)
X = []
Y = []

if __name__ == "__main__":
    n = int(input())
    maxn = 0
    index = 0
    for i in range(n):
        x, y = map(int, input().split())
        A.append((x, y))
        X.append(x)
        Y.append(y)

    X.sort()
    Y.sort()
    res = INF
    for i in range(n):
        x1 = X[1] if A[i][0] == X[0] else X[0]
        x2 = X[n - 2] if A[i][0] == X[n - 1] else X[n - 1]
        y1 = Y[1] if A[i][1] == Y[0] else Y[0]
        y2 = Y[n - 2] if A[i][1] == Y[n - 1] else Y[n - 1]
        res = min(res, (x2 - x1) * (y2 - y1))
    print(res)
