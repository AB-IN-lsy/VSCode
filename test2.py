def find(x):
    if fa[x] == x:
        return x
    return fa[x] = find(fa[x])
def join(x, y):
    fa[find(x)] = find(y)

n, m, t = map(int, input().split())
ls = [0]
for i in range(1, n):
    ls.append(i)
for _ in range(m):
    a, b = map(int, input().split())
    join(find(a), find(b))
for _ in range(t):
    if find(a) == find(b):
        print("YES")
    else:
        print("NO")