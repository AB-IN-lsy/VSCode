'''
Author: NEFU AB-IN
Date: 2022-05-21 15:10:54
FilePath: \ACM\Acwing\2012.py
LastEditTime: 2022-05-21 15:39:50
'''
n = int(input())

a = []
for i in range(n):
    a.append(int(input()))

b = set(a)
ans = 0

for x in b:  # 枚举被删除的元素
    i = 0  # 左端点
    while i < n:
        cnt = 0
        while i < n and a[i] == x:
            i += 1
        j = i  # 右端点
        while j < n and (a[j] == a[i] or a[j] == x):
            if a[j] == a[i]:
                cnt += 1
                ans = max(ans, cnt)
            j += 1
        i = j - 1
        i += 1

print(ans)
