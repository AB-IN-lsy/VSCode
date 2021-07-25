def f(m,n):
    if m==0 or n==0 :return 1
    return f(m-1,n)+f(m,n-1)
s=input()
c=input()
s_ans=0
c_ans=0
cnt=0
for i in s:
    if i == "+":
        s_ans+=1
    if i == "-":
        s_ans-=1
for i in c:
    if i == "+":
        c_ans+=1
    if i == "-":
        c_ans-=1
    if i == "?":
        cnt+=1
if c.find("?")==-1 and s_ans==c_ans:
    print("1.000000000000")
elif c.find("?")==-1 and s_ans!=c_ans:
    print("0.000000000000")
elif abs(s_ans-c_ans)>cnt:
    print("0.000000000000")
else:
    cha=s_ans-c_ans #需要多少加号
    jia=0
    jian=0
    if cha>0:
        jia+=cha
    else:
        jian-=cha
    jia+=(cnt-abs(cha))//2
    jian+=(cnt-abs(cha))//2
    print(f'{f(jia,jian)/2**cnt:.9f}')



