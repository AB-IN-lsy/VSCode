'''
Author: NEFU AB-IN
Date: 2022-04-13 20:07:43
FilePath: \ACM\GPLT\L1-008.PY
LastEditTime: 2022-04-13 20:07:43
'''
l, r = map(int, input().split())

ans, cnt = 0, 0
for i in range(l, r + 1):
    if cnt == 5:
        cnt = 0
        print()
    cnt += 1
    print(f"{i:>5}", end="")
    ans += i
print()
print(f"Sum = {ans}")