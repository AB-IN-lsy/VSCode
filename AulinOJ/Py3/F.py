import itertools as it
t=int(input())
while t>0:
    n=int(input());ans=0
    for i in range(1,n+1):
        ans+=(i%(1e9+7))*(len(set(it.combinations(range(1,n+1),i)))%(1e9+7))
    print(int(ans%(1e9+7)))