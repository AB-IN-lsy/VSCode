def f(s,k):
    mu_ban="0123456789ABCDEF";a=""
    while s>0:
        yu_shu=s%k
        s=s//k
        a+=mu_ban[yu_shu]
    return a[::-1]
n=int(input())
m=input();ans=0
while ans<30 and (m!=m[::-1]):
    m=f(int(m,n)+int(m[::-1],n),n)
    ans+=1
if ans>=30:
    print("Impossible!")
else:
    print(f'STEP={ans}')