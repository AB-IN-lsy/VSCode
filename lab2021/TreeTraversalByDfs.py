'''
Description: file content
Author: NEFU AB_IN
version: 1.0
Date: 2021-05-31 20:28:18
LastEditors: NEFU AB_IN
LastEditTime: 2021-05-31 20:28:29
'''
'''
Description: file content
Author: NEFU AB_IN
version: 1.0
Date: 2021-01-28 23:02:48
LastEditors: NEFU AB_IN
LastEditTime: 2021-05-31 20:27:03
'''
N = 10
h = [-1 for i in range(N)]
ne = [0 for i in range(N)]
e = [0 for i in range(N)]
color = [0 for i in range(N)] #white = 0, grey = 1, black = 2
seen = [0 for i in range(N)]
done = [0 for i in range(N)]

idx = 0
time = 0

def add(a, b):
    global idx
    e[idx] = b
    ne[idx] = h[a]
    h[a] = idx
    idx += 1

def dfs(u):
    global time
    color[u] = 1
    seen[u] = time
    time += 1
    i = h[u]
    while i != -1:
        j = e[i]
        if color[j] == 0:
            dfs(j)
        i = ne[i]
    color[u] = 2
    done[u] = time
    time += 1

n, m = map(int, input().split()) #input n points from [1, n], m edges
for _ in range(m):
    a, b = map(int, input().split())
    add(a, b)

for i in range(1, n + 1):
    if color[i] == 0:
        dfs(i)

print("seen:", *seen)
print("done:", *done)

'''
5 7
1 2
2 3
3 4
1 3
2 5
5 1
5 4
'''
