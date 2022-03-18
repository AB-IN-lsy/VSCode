'''
Author: NEFU AB-IN
Date: 2022-03-17 17:13:23
FilePath: \ACM\Acwing\3297.py
LastEditTime: 2022-03-17 17:13:24
'''
n = int(input())
ans = 0
for i in range(n):
    w, score = map(int, input().split())
    ans += w * score
print(max(0, ans))