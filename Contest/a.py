l, r = map(int, input().split())
s = input()
ans = 0

lst = dict()
cnt = dict()
for i in range(0, len(s)):
    if s[i] == '0':
        ans += 1
    if s[i] != '0':
        lst[i] = ans
        ans = 0
ans = 0

for i in range(len(s)):
    c = 0
    if s[i] == "0":
        cnt[i] = 0
        continue
    for j in range(i + 1, len(s) + 1):
        if int(s[i:j]) >= l and int(s[i:j]) <= r:
            ans += 1
            c += 1
    cnt[i] = c

for i in lst:
    ans += cnt[i] * lst[i]
print(ans)
    