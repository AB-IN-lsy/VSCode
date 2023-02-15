from collections import Counter, defaultdict

ans = []
g = []

for _ in range(3):  #横行
    s = input()
    d = Counter(s)
    ans.append(d)
    g.append(s)

for j in range(3):  #纵行
    d = Counter()
    for i in range(3):
        d[g[i][j]] += 1
    ans.append(d)

d = Counter()
for i in range(3):  #正对角线
    d[g[i][i]] += 1
ans.append(d)

d = Counter()
for i in range(3):  #反对角线
    d[g[i][3 - i - 1]] += 1
ans.append(d)

st = defaultdict(int)
cnt1, cnt2 = 0, 0
for d in ans:
    s = ""
    for key in sorted(d.keys()):
        s += key
    if len(d) == 1 and st[s] == 0:
        cnt1 += 1
        st[s] += 1
    if len(d) == 2 and st[s] == 0:
        cnt2 += 1
        st[s] += 1

print(cnt1)
print(cnt2)
