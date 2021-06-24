'''
Description: file content
Author: NEFU AB_IN
version: 1.0
Date: 2021-06-24 16:01:01
LastEditors: NEFU AB_IN
LastEditTime: 2021-06-24 17:00:39
'''
ans = []
def PrintRec(rec, i, j):
    if i == j:
        ans.append(j)
    else:
        if rec[i][j] == inf:
            return False
        else:
            PrintRec(rec, i, rec[i][j])
            ans.append(j)


# n vertexes, m edges, q queries
n, m, q = map(int, input().split())
inf = 0x3f3f3f3f

# vertex range [1, n]
dist = [[inf for _ in range(n + 1)] for _ in range(n + 1)]
rec = [[inf for _ in range(n + 1)] for _ in range(n + 1)]
for i in range(n + 1):
    dist[i][i] = 0

for _ in range(m):
    u, v, w = map(int, input().split())
    dist[u][v] = min(dist[u][v], w)
    rec[u][v] = u

for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if dist[u][v] > dist[u][k] + dist[k][v]:
                dist[u][v] = dist[u][k] + dist[k][v]
                rec[u][v] = rec[k][v]

for _ in range(q):
    u, v = map(int, input().split())
    ans = []
    if dist[u][v] > inf / 2:
        print("impossible")
    else:
        print("distance: " , dist[u][v])
        if PrintRec(rec, u, v) == False:
            print(f"no path from {u} to {v}")
        else:
            print("Path: ", *ans)

