while True:
    try:
        s=input().split("+")
        ans=0
        for i in range(len(s)):
            if 'd' in s[i]:
                n,x=s[i].split("d")
                ans+=(int)(n)*(int(x)+1)*0.5
            else:
                ans+=int(s[i])
        if ans*10%10==0:
            print(int(ans))
        else:
            print(int(ans)+0.5)
    except:
        break
                
