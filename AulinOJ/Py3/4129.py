ans=input()
while True:
    try:
        a=0;b=0
        s=input()
        for i in range(len(ans)):
            if ans[i]==s[i]:
                a+=1
            elif s[i] in ans:
                b+=1
        print(f'{a}A{b}B')
    except:
        break