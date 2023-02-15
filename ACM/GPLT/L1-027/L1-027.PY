'''
Author: NEFU AB-IN
Date: 2022-04-15 16:06:03
FilePath: \ACM\GPLT\L1-027.PY
LastEditTime: 2022-04-15 16:29:13
'''
from copy import deepcopy
from collections import Counter

s = list(map(int, input()))

ss = deepcopy(s)
ss = sorted(list(set(s)), reverse=True)

d = Counter()
for i in range(len(ss)):
    d[ss[i]] = i

ans = []
for i in range(len(s)):
    ans.append(d[s[i]])

print(f"int[] arr = new int[]{{{','.join(map(str, ss))}}};")
print(f"int[] index = new int[]{{{','.join(map(str, ans))}}};")
