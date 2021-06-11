'''
Description: file content
Author: NEFU AB_IN
version: 1.0
Date: 2021-06-11 08:57:45
LastEditors: NEFU AB_IN
LastEditTime: 2021-06-11 09:05:20
'''
judge = False

def dfs(adj_matrix, i, d, color, N):
    global judge
    if judge == True:
        return
    color[i] = 1
    for j in range(N):
        if adj_matrix[i][j] == 1 and color[j] == 0:
            if j == d:
                judge = True
                return
            dfs(adj_matrix, j, d, color, N)
    color[i] = 2
    
def is_reachable(adj_matrix, s, d):
    N = len(adj_matrix)
    color = [0 for _ in range(N)] #white = 0, grey = 1, black = 2
    global judge
    judge = False
    if s == d:
        return True
    dfs(adj_matrix, s, d, color, N)
    return judge


adj_matrix = [[0,1,1,0],[0,0,1,0],[1,0,0,0],[0,1,0,0]]
print(is_reachable(adj_matrix, 0, 3))
print(is_reachable(adj_matrix, 3, 0))