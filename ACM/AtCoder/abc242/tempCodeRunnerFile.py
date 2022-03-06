'''
Author: NEFU AB-IN
Date: 2022-03-05 20:19:08
FilePath: \ACM\AtCoder\abc242\tempCodeRunnerFile.py
LastEditTime: 2022-03-06 10:54:41
'''
res = 0
for j in range(1, 10):
    for k in range(1, 10):
        if abs(j - k) <= 1:
            res += 1
            print(j * 10 + k, end=" ")
