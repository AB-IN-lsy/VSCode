s=input()
m="RBYG"
for i in m:
    index=s.find(i)%4
    cnt=0
    while index<len(s):
        if s[index]=="!":
            cnt+=1
        index+=4
    print(cnt,end=" ")
    
