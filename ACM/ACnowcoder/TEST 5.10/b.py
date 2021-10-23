while True:
    try:
        s=input().split("+")
        ans=0
        for i in s:
            if i.find('d')!=-1:
                n,x=i.split("d")
                ans+=(int)(n)*(int(x)+1)*0.5
            else:
                ans+=int(i)
        if ans%1==0:
            print(int(ans))
        else:
            print(int(ans)+0.5)
    except:
        break
                
