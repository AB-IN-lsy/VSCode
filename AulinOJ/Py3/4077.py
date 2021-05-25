def dg(s):
    ans=0
    for i in s:
        ans+=int(i)
    return ans
s=input("The number: ")
ans=0
while(len(s)>1):
    ans=dg(s)
    s=str(ans)
print(f'The digit total: {ans}')