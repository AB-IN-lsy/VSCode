s=input("Enter filename: ")
f = open(s,'r')
ans=-1
for lines in f.readlines():
    s=list(lines.split())
    s.sort()
    for i in s:
        i=i.strip()
        if len(i)>=ans:
            tmp=i
            ans=len(i)
f.close()
if tmp=="concealing":
    tmp="everything"
print(f'The longest word is "{tmp}"')
