from math import gcd
for _ in range(int(input())):
    n=int(input())
    lst=list(map(int,input().split()))
    maxn=max(lst)
    fin=[]
    while lst:
        curr = max((gcd(maxn,i),i) for i in lst)
        lst.remove(curr[1])
        fin.append(curr[1])
        maxn = curr[0]
    print(*fin)