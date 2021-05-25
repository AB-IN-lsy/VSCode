t=int(input())
while t>0:
    t=-1
    input()
    a=list(map(int,input().split()))
    a.sort()
    r=list(range(len(a),0,-1))
    ans=sum([a[i]*r[i]for i in range(len(a))])/len(a)
    print("%.2f"%ans)