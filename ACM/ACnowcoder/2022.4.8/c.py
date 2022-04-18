'''
Author: NEFU AB-IN
Date: 2022-04-08 21:35:57
FilePath: \ACM\ACnowcoder\2022.4.8\c.py
LastEditTime: 2022-04-08 21:35:58
'''
n = int(input())

a = list(map(int, input().split()))
x = int(input())

a = [0, *a]

index = n + 1
p = 0
stk = []

for i in range(1, n + 1):
    if a[i] > x:
        stk.append(i)
ans = 0
while True:
    if stk:
        tmp = stk[-1]
        if p < tmp:
            index = tmp
            stk.pop()
            ans += 1
        else:
            ans += max(0, index - p)
            print(ans)
            exit(0)
    else:
        ans += max(0, index - p)
        print(ans)
        exit(0)
    p += 1