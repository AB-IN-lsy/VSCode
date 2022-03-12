'''
Author: NEFU AB-IN
Date: 2022-03-12 18:59:48
FilePath: \ACM\Acwing\42\a.py
LastEditTime: 2022-03-12 19:03:58
'''
n, m = map(int, input().split())
minn = int(2e9)
for i in range(n):
    a, b = map(int, input().split())
    minn = min(minn, a / b)
print(f'{m * minn:.6f}')