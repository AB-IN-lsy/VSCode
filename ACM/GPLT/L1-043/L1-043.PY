'''
Author: NEFU AB-IN
Date: 2022-04-15 19:55:54
FilePath: \ACM\GPLT\L1-043.PY
LastEditTime: 2022-04-15 19:59:52
'''
from collections import Counter

S = Counter()

n = int(input())

while n > 0:
    cnt, time_sum = 0, 0
    while True:
        index, op, time = input().split()
        h, f = map(int, time.split(':'))
        if index == '0':
            if cnt == 0:
                print(0, 0)
            else:
                print(cnt, int((time_sum / cnt) + 0.5))
            break
        if op == 'S':
            # if S[index]:
            #     continue
            S[index] = [h, f]
        else:
            if not S[index]:
                continue
            time_sum += (h - S[index][0]) * 60 + (f - S[index][1])
            S[index] = 0
            cnt += 1
    n -= 1