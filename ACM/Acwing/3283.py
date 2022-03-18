'''
Author: NEFU AB-IN
Date: 2022-03-18 16:14:13
FilePath: \ACM\Acwing\3283.py
LastEditTime: 2022-03-18 16:14:23
'''
n = int(input())

ans = [0, 0, 0, 0, 0]

i = 1
cnt = 1
while cnt <= n:
    if i % 7 == 0 or str(i).count("7"):
        ans[(i - 1) % 4 + 1] += 1
    else:
        cnt += 1
    i += 1
for i in range(1, 5):
    print(ans[i])