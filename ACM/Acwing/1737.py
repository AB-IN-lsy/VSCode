'''
Author: NEFU AB-IN
Date: 2022-04-01 21:02:53
FilePath: \ACM\Acwing\1737.py
LastEditTime: 2022-04-01 21:02:53
'''
a, b, x, y = map(int, input().split())

res = abs(b - a)

# 路径选择: a -> x, x -> y, y -> b
tmp = abs(a - x)
tmp += abs(y - b)
res = min(res, tmp)
# 路径选择: a -> y, y -> x, x -> b
tmp = abs(a - y)
tmp += abs(x - b)
res = min(res, tmp)

print(res)
