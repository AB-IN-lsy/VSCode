while True:
    try:       
        k,n=input().split()
        ans=0
        s=str(bin(int(n)))
        s1=s[2:]
        l=len(s1)-1
        for i in range(len(s1)):
            ans+=(int)(s1[i]) * (int(k)**int(l-i))
        print(ans)
    except:
        break
