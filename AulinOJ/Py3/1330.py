def f(s):
    if s==s[::-1]:
        return True
    else:
        return False
while True:
    try:
        s=input();ans=0
        for i in range(len(s)):
            for j in range(i,len(s)):
                if f(s[i:j+1]):
                    ans=max(len(s[i:j+1]),ans)
        print(ans)
    except:
        break