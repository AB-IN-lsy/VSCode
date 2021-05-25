n=int(input())
tmp=input().split()
lst=[float(i) for i in tmp]
print(f'{(sum(lst)-max(lst)-min(lst))/(n-2):.2f}')