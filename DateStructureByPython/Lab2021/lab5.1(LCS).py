'''
Description: file content
Author: NEFU AB_IN
version: 1.0
Date: 2021-06-06 15:44:16
LastEditors: NEFU AB_IN
LastEditTime: 2021-06-07 21:56:01
'''
from typing import List
# find length of the longest common subsequence of two sequences x and y
# m is the length of sequence x
# n is the length of sequence y
# c stores optimal values of subproblems
# rec is used to record computing information
def LCSLength(x: str, y: str, m: int, n: int, c: List[List[int]], rec: List[List[int]]):
    for i in range(m + 1):
        a = [0 for _ in range(n + 1)]
        b = [0 for _ in range(n + 1)]
        c.append(a)
        rec.append(b)
    
    for i in range(1, m + 1):#从1开始，【0，】，【，0】的行列均是边界
        for j in range(1, n + 1):
            if x[i - 1] == y[j - 1]: #不减一的话会超string的index_range
                c[i][j] = c[i - 1][j - 1] + 1
                rec[i][j] = 12 #up_left
            elif c[i - 1][j] >= c[i][j - 1]:
                c[i][j] = c[i - 1][j]
                rec[i][j] = 1 #up
            else:
                c[i][j] = c[i][j - 1]
                rec[i][j] = 2 #left
    return rec

# construct optimal solution

cnt = 0
ans = []
def PrintLCS(rec: List[List[int]], x: str, i:int, j:int):
    if i == 0 or j == 0:
        return
    if rec[i][j] == 12:
        PrintLCS(rec, x, i - 1, j - 1)
        global cnt
        cnt += 1
        ans.append(x[i - 1])
    elif rec[i][j] == 1:
        PrintLCS(rec, x, i - 1, j)
    else:
        PrintLCS(rec, x, i, j - 1)

# print length of the longest common subsequence
# print the longest common subsequence
def LCS(x:str, y:str):
    c = list()
    rec = list()
    rec = LCSLength(x, y, len(x), len(y), c, rec)
    PrintLCS(rec, x, len(x), len(y))
    print(cnt)
    print("".join(ans))