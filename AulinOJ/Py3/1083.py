while True:
    try:
        c=input().strip();ans=0
        s=c.split("-")
        ans+=int(s[0])
        cnt=1
        for j in range(1,3):
            for i in s[j]:
                cnt+=1
                ans+=int(i)*cnt
        ans=ans%11
        if ans==10:
            n='X'
        else:
            n=str(ans)
        if n==s[3]:
            print("Right")
        else:
            print(c[:12],end=n)
            print()
    except:
        break       