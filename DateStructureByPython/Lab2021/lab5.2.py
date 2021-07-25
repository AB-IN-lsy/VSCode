'''
Description: file content
Author: NEFU AB_IN
version: 1.0
Date: 2021-06-06 18:59:46
LastEditors: NEFU AB_IN
LastEditTime: 2021-06-08 13:00:55
'''
from typing import List
# find the maximum value of knapsack
# n is the number of items
# C is the maximum capacity of knapsack
# v lists values of the items, the ith item is worth vi
# w lists weight of the items, the ith item weighs wi
# m stores the optimal values of subproblems
# rec is used to record computing information
# 二维背包无优化版
def find_optimal_value(n: int, C: int, v: List[int], w: List[int], m: List[List[int]], rec: List[List[int]]):
    for i in range(n + 1):
        a = [0 for _ in range(C + 1)]
        b = [0 for _ in range(C + 1)]
        m.append(a)
        rec.append(b)
    for i in range(1, n + 1):
        for j in range(1, C + 1):
            if j < w[i]:
                m[i][j] = m[i - 1][j]
                rec[i][j] = rec[i - 1][j]
            else:
                m[i][j] = max(m[i - 1][j], m[i - 1][j - w[i]] + v[i])
                rec[i][j] = max(rec[i - 1][j], rec[i - 1][j - w[i]] + v[i])
    return rec

# construct the optimal solution
def find_optimal_solution(rec: List[List[int]], i: int, j: int, v: List[int], w: List[int], ans: List[int]):
    if i >= 0:
        if rec[i][j] == rec[i - 1][j]:
            ans[i] = 0
            find_optimal_solution(rec, i - 1, j, v, w, ans)
        elif j - w[i] >= 0 and rec[i][j] == rec[i - 1][j - w[i]] + v[i]:
            ans[i] = 1
            find_optimal_solution(rec, i - 1, j - w[i], v, w, ans)
    
# print the optimal value and optimal solution   
def knapsack(C: int, n: int, v: List[int], w: List[int]):
    rec = list()
    m = list()
    rec = find_optimal_value(n, C, v, w, m, rec)
    ans =[0 for i in range(n + 1)]
    find_optimal_solution(rec, n, C, v, w, ans)
    print(rec[n][C])
    print(ans)
    return 0

C = 16  # the maximum capacity of knapsack
n = 3   # the number of items
v = [-1, 5, 4, 1]   # values of the items, the ith item is worth vi 
w = [-1, 10, 8, 5]  # weight of the items, the ith item weighs wi
knapsack(C, n, v, w)

