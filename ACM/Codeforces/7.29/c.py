def solve(s, x, y):
    result = 0
    for a in s:
        if int(a)==x:
            result += 1
            x, y = y, x
    if x!=y and result%2==1:
        result -= 1
    return result
 
t = int(input())
for _ in range(t):
    s = input()
    ans = 0
    for x in range(10):
        for y in range(10):
            ans = max(ans, solve(s, x, y))
    print(len(s)-ans)