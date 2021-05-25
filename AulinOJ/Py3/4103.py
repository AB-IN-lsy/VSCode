n=int(input())
tmp=input().split()
lst=[int(i) for i in tmp]
for i in range(len(lst)):
    if lst[i]==max(lst):
        print(f'{max(lst)} {i+1}')
        break
for i in range(len(lst)):
    if lst[i]==min(lst):
        print(f'{min(lst)} {i+1}')
        break