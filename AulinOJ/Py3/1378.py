n=int(input())
lst=[int(i) for i in range(n+1)]
i=1;j=1;sum1=lst[1]
while i<=j and j<n:
    if sum1>=n:
        if sum1==n:
            print(i,j)
        sum1-=lst[i]
        i+=1
    else:
        j+=1
        sum1+=lst[j]