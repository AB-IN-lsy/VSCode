'''
Author: NEFU AB-IN
Date: 2022-03-19 12:27:07
FilePath: \ACM\Acwing\1442.py
LastEditTime: 2022-03-19 12:27:08
'''
n, k = map(int, input().split())

words = list(input().split())

cnt = k
for i in range(n):
    if len(words[i]) > cnt:
        print()
        cnt = k
    print(words[i], end = " ")
    cnt -= len(words[i])