'''
Author: NEFU AB-IN
Date: 2021-12-01 20:54:51
FilePath: \DCAS\ProbabilityStatistics.py
LastEditTime: 2021-12-01 21:06:31
'''
s = input()
cnt = 0
dict_cnt = {}
for i in s:
    if i.isalpha():
        cnt += 1
        try:
            dict_cnt[i.lower()] += 1
        except:
            dict_cnt.setdefault(i.lower(), 1)
lst = []
for i in dict_cnt:
    lst.append((i, dict_cnt[i] / cnt))
lst.sort(key=lambda x: x[1], reverse=True)
for i in lst:
    print(f'{i[0]} : {i[1]:.3f}')
