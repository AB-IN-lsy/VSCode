'''
Author: NEFU AB-IN
Date: 2022-05-22 20:59:08
FilePath: \ACM\Acwing\3359.1.py
LastEditTime: 2022-05-22 21:47:50
'''
n = int(input())

odd, even = 0, 0

a = list(map(int, input().split()))

for i in a:
    if i & 1:
        odd += 1
    else:
        even += 1

while odd > even:
    odd -= 2
    even += 1

if odd == even:
    print(odd * 2)
else:
    print(odd * 2 + 1)