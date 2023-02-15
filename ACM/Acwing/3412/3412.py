'''
Author: NEFU AB-IN
Date: 2022-03-17 17:05:12
FilePath: \ACM\Acwing\3412.py
LastEditTime: 2022-03-17 17:05:13
'''
N = 650
s = [[0] * N for _ in range(N)]
a = [[0] * N for _ in range(N)]

n, L, r, t = map(int, input().split())
for i in range(1, n + 1):
    a[i][1:] = list(map(int, input().split()))

for i in range(1, n + 1):
    for j in range(1, n + 1):
        s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j]

ans = 0
for i in range(1, n + 1):
    for j in range(1, n + 1):
        x1, y1, x2, y2 = max(i - r, 1), max(j - r, 1), min(i + r,
                                                           n), min(j + r, n)
        sum = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]
        cnt = (x2 - x1 + 1) * (y2 - y1 + 1)
        # print(sum / cnt, sum, x1, y1, x2, y2)
        if sum / cnt <= t:
            ans += 1

print(ans)