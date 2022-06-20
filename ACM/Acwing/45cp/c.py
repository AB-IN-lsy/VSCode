'''
Author: NEFU AB-IN
Date: 2022-04-02 18:57:40
FilePath: \ACM\Acwing\45\c.py
LastEditTime: 2022-04-02 19:46:42
'''
from sortedcontainers import SortedList

INF = int(1e18)

n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

ans = -INF
matrix = [[0] * m for _ in range(n)]
for i in range(n):
    for j in range(m):
        matrix[i][j] = a[i] * b[j]

m, n = len(matrix), len(matrix[0])
k = int(input())
for i in range(m):  # 枚举上边界
    total = [0] * n
    for j in range(i, m):  # 枚举下边界
        for c in range(n):
            total[c] += matrix[j][c]  # 更新每列的元素和

        totalSet = SortedList([0])
        s = 0
        for v in total:
            s += v
            lb = totalSet.bisect_left(s - k)
            if lb != len(totalSet):
                ans = max(ans, s - totalSet[lb])
            totalSet.add(s)

print(ans)
