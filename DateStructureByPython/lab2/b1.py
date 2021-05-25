n=int(input("Enter an integer: "))
s=input("Enter a filename: ")
f = open(s,'r')
ans=0
for lines in f.readlines():
    lst=list(map(lambda x:int(x)%n==0,lines.split()))
    ans+=lst.count(True)
f.close()
if ans==1:
    print(f"There is {ans} multiple of {n} in the '{s}' file.")
else:
    print(f"There are {ans} multiples of {n} in the '{s}' file.")