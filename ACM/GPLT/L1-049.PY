'''
Author: NEFU AB-IN
Date: 2022-04-16 17:05:57
FilePath: \ACM\GPLT\L1-049.PY
LastEditTime: 2022-04-16 17:05:58
'''
N = 110
pos = [[[0] * N for _ in range(N)] for _ in range(N)]
# pos[i][j][k] 代表第i个学校，第j个队伍，第k个队员的位置

n = int(input())

a = [0, *list(map(int, input().split()))]

mx = max(a)
pre, x = 0, 0
for j in range(1, mx + 1):
    for k in range(1, 11):
        for i in range(1, n + 1):
            if j <= a[i]:
                if pre == i:
                    x += 2
                else:
                    x += 1
                pos[i][j][k] = x
                pre = i

for i in range(1, n + 1):
    print(f"#{i}")
    for j in range(1, a[i] + 1):
        for k in range(1, 11):
            print(pos[i][j][k], end=" " if k < 10 else "")
        print()