n=int(input("Enter number of rows: "))
print("*"*n)
for i in range(2,n):
    if i>(n//2)+1:
        i=(n+1)-i
    if i==(n//2+1):
        print("*"+(n-3)//2*" "+"*"+(n-3)//2*" "+"*")
    else:
        print("*"+(i-2)*" "+"*"+(n-2*i)*" "+"*"+(i-2)*" "+"*")
print("*"*n)