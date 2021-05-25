while True:
    try:
        n=int(input())
        a=[[0 for i in range(1,n+2)] for j in range(1,n+2)]
        cnt=1
        i=1;j=1
        while cnt<=n*n:
            while(j<=n and not a[i][j]):
                a[i][j]=cnt
                cnt+=1
                j+=1
            while(i<=(n-1) and not a[i+1][j-1]):
                a[i+1][j-1]=cnt
                cnt+=1
                i+=1
            while(j>=3 and not a[i][j-2]):
                a[i][j-2]=cnt
                cnt+=1
                j-=1
            while(i>=3 and not a[i-1][j-1]):
                a[i-1][j-1]=cnt
                cnt+=1
                i-=1
        for i in range(1,n+1):
            for j in range(1,n+1):
                print(a[i][j],end=" ")
            print()
    except:
        break