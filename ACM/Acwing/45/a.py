'''
Author: NEFU AB-IN
Date: 2022-04-02 18:57:34
FilePath: \ACM\Acwing\45\a.py
LastEditTime: 2022-04-02 21:00:23
'''
from collections import Counter

a = list(map(int, input().split()))
a = [0, *a]
s = input()
d = Counter(s)
ans = 0

for key in sorted(d.keys()):
    ans += a[int(key)] * d[key]

print(ans)