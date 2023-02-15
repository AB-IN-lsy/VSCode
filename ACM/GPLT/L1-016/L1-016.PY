'''
Author: NEFU AB-IN
Date: 2022-04-14 09:53:17
FilePath: \ACM\GPLT\L1-016.PY
LastEditTime: 2022-04-14 09:58:04
'''
d = [7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2]
m = ['1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2']
n = int(input())

ans = []
for i in range(n):
    s = input()
    cnt = 0
    for j in range(len(s) - 1):
        if s[j].isdigit():
            cnt += int(s[j]) * d[j]
        else:
            ans.append(s)
            break
    if m[cnt % 11] != s[-1]:
        ans.append(s)
if len(ans) == 0:
    print("All passed")
else:
    for i in ans:
        print(i)
