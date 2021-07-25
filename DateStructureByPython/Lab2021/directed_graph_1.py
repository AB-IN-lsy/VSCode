'''
Description: file content
Author: NEFU AB_IN
version: 1.0
Date: 2021-06-25 08:43:20
LastEditors: NEFU AB_IN
LastEditTime: 2021-06-25 20:24:25
'''

def find_directed_girth(adj_list):
    # n vertexes
    n = len(adj_list)
    inf = float('inf')
    ans = inf
    # vertex range [0, n - 1]
    dist = [[inf for _ in range(n)] for _ in range(n)]
    a = [[inf for _ in range(n)] for _ in range(n)]
    for i in range(n):
        dist[i][i] = 0
        a[i][i] = 0

    for i in range(len(adj_list)):
        for j in adj_list[i]:
            dist[i][j] = 1
            a[i][j] = 1
    
    for k in range(n):
        for i in range(k):
            for j in range(i + 1, k):
                ans = min(a[i][k] + a[k][j] + dist[j][i], ans)
                # key point, i -> k -> (j -> i), so is dist[j][i], not dist[i][j]
        
        for i in range(n):
            for j in range(n):
                if dist[i][j] > dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]

    if ans == inf:
        return 'inf'
    else:
        return ans
        
adj_list = [[], [2], [4], [2], [3], [1]]
print(find_directed_girth(adj_list))
# 3
# 2 -> 4 -> 3 -> 2
adj_list = [[], [2, 5], [4], [2], [3], [1]]
print(find_directed_girth(adj_list))

# 2
# 1 -> 5 -> 1