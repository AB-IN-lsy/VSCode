ans=0
while True:
    try:
        s=bin(int(input()))[2:]
        if s[::-1]==s and len(s)>1:
            ans+=1
    except:
        break
print(ans)
