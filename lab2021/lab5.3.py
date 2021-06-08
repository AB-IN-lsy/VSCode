'''
Description: file content
Author: NEFU AB_IN
version: 1.0
Date: 2021-06-06 20:44:37
LastEditors: NEFU AB_IN
LastEditTime: 2021-06-06 20:54:01
'''
# a is list of jobs, which are presented by time intervals.
def job_selection(a):
    a.sort(key = lambda x : x[1])
    k = 0
    b = [a[0]]
    for i in range(1, len(a)):
        if a[i][0] >= a[k][1]:
            b.append(a[i])
            k = i
    return b

print(job_selection([(1, 4), (3, 5), (4, 6), (5, 7), (6, 9)]))
