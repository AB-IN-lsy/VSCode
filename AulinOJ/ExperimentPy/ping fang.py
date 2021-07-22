def power2(n):
    return n**2
try:
    num=input()
    num=eval(num)
    ans=power2(num)
    print(num,"**2=",ans)
except ValueError:
    print("error")
