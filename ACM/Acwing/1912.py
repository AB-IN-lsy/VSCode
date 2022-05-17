'''
Author: NEFU AB-IN
Date: 2022-05-16 09:35:56
FilePath: \ACM\Acwing\1912.py
LastEditTime: 2022-05-16 10:06:36
'''
from bisect import bisect_left, bisect_right

a, b = map(int, input().split())

al = len(str(a))
bl = len(str(b))

ans = []

for i in range(al, bl + 1):  # 枚举位数
    for j in range(10):  # 枚举串的模板 如 1111
        s = list(str(j) * i)
        for k in range(i):  # 枚举特殊数的放置地方 如 0
            tmp = s[:]
            for q in range(10):  # 枚举特殊数的数值 如 2
                if q == j:  # 相等时跳过
                    continue
                tmp[k] = str(q)  # 临时串
                res = int("".join(tmp))  # 其中一个结果 即为 2111
                if len(str(res)) == i:
                    ans.append(res)
                tmp = s[:]

ans = sorted(list(set(ans)))

print(bisect_right(ans, b) - bisect_left(ans, a))