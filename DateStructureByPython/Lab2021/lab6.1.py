'''
Description: file content
Author: NEFU AB_IN
version: 1.0
Date: 2021-06-11 08:15:03
LastEditors: NEFU AB_IN
LastEditTime: 2021-06-11 08:55:35
'''
time = 0

def dfs(adj_matrix):
    N = len(adj_matrix)
    color = [0 for _ in range(N)] #white = 0, grey = 1, black = 2
    seen = [0 for _ in range(N)]
    done = [0 for _ in range(N)]
    tree = []
    forward = []
    back = []
    cross = []
    for i in range(N):
        if color[i] == 0:
            dfs_main_fuc(adj_matrix, i, tree, color, seen, done, N)
    for i in range(N):
        for j in range(N):
            if adj_matrix[i][j] == 1:
                if seen[i] < seen[j] < done[j] < done[i]:
                    forward.append((i, j))
                if seen[j] < seen[i] < done[i] < done[j]:
                    back.append((i, j))
                if seen[j] < done[j] < seen[i] < done[i]:
                    cross.append((i, j))
    tree.sort()
    forward.sort()
    back.sort()
    cross.sort()
    return tree, forward, back, cross
def dfs_main_fuc(adj_matrix, i, tree, color, seen, done, N):
    global time
    color[i] = 1
    seen[i] = time
    time += 1
    for j in range(N):
        if adj_matrix[i][j] == 1 and color[j] == 0:
            tree.append((i, j))
            adj_matrix[i][j] = 0
            dfs_main_fuc(adj_matrix, j, tree, color, seen, done, N)
    color[i] = 2
    done[i] = time
    time += 1


adj_matrix = [[0,1,1,1],[0,0,0,1],[0,0,0,1],[0,0,0,0]]
tree, forward, back, cross = dfs(adj_matrix)
print('Tree arcs: {}'.format(tree))
print('Forward arcs: {}'.format(forward))
print('Back arcs: {}'.format(back))
print('Cross arcs: {}'.format(cross))