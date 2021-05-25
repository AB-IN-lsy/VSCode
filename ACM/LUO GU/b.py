num=['0','1','2','3','4','5','6','7','8','9']
s=list(input().split("("))
cnt=0
print(s)
for i in s:
    ans=0
    tmp=0
    for j in range(len(i)):
        ans=0
        n=''
        c=j+1
        while c<len(i) and i[c] in num:
            n=n+i[c]
            c+=1
        
        if i[j]==")":
            if n=='':
                continue
            ans+=tmp*(int(n)-1)
        
        if i[j]=="H" and n!='':
            ans+=1*int(n)
        elif i[j]=="H":
            ans+=1
        
        if i[j]=="C" and n!='':
            ans+=13*int(n)
        elif i[j]=="C":
            ans+=13
        
        if i[j]=="O" and n!='':
            ans+=17*int(n)
        elif i[j]=="O":
            ans+=17
        tmp+=ans
        cnt+=ans
        
        
print(cnt)
