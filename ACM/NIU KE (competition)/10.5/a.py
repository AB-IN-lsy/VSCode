n=int(input())
lst=list(map(int,input().split()))
print(max(lst)*n-sum(lst))