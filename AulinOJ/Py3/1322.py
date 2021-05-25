def reverse(s):
    return s[::-1]
def judge(s):
    s3=s[::-1]
    if s3==s:
        return 1
    else:
        return 0
    
t=int(input())
while t>0:
    t=t-1
    s1=input()
    n=0
    while True:
        s2=reverse(s1)
        s1=int(s1)+int(s2)
        s1=str(s1)
        n+=1
        judge1=judge(s1)
        if judge1:
            break
    if n>8:
        print("0")
    else:
        print(n)
    

