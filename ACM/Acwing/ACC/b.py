'''
Author: NEFU AB-IN
Date: 2022-03-20 18:55:41
FilePath: \ACM\Acwing\ACC\b.py
LastEditTime: 2022-03-20 20:17:56
'''

for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    t = 0
    while True:
        t += 1
        flag = 0
        b = [0] * 250
        for i in range(k):
            b[max(a[i] - (t - 1), 0)] += 1
            b[min(a[i] + t, n + 9)] -= 1
        for i in range(1, n + 1):
            b[i] += b[i - 1]
            if b[i] == 0:
                flag = 1
        if flag == 0:
            break
    print(t)
