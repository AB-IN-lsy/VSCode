'''
Author: NEFU AB-IN
Date: 2022-04-13 18:33:28
FilePath: \ACM\GPLT\L1-006.PY
LastEditTime: 2022-04-13 19:05:33
'''
from collections import Counter
from copy import deepcopy

n = int(input())
v = []
i = 1
while i <= n // i:
    if n % i == 0:
        v.append(i)
        if i != n // i:
            v.append(n // i)
    i += 1
v.sort()

if n == 1:
    print(0)
    exit(0)
if len(v) == 2:
    print(1)
    print(n)
    exit(0)

v = v[1:len(v) - 1]
mx = 0
ans = 1
cnt = v[0]
res = [v[0]]
d = Counter(v)

i = 0
while i < len(v):
    if i == 0:
        ans, cnt, res = 1, v[i], [v[i]]
        i += 1
        continue
    if v[i - 1] + 1 == v[i] and v[i] * cnt <= n and n % (v[i] * cnt) == 0:
        ans += 1
        cnt *= v[i]
        res.append(v[i])
        if ans > mx:
            mx = ans
            kkk = deepcopy(res)
    else:
        if v[i - 1] + 1 == v[i]:
            i -= 1
        res = [v[i]]
        ans = 1
        cnt = v[i]
    i += 1

if ans > mx:
    mx = ans
    kkk = deepcopy(res)
print(mx)
kkk = list(map(str, kkk))
print("*".join(kkk))