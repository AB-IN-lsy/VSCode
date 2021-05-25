cnt=0
for i in range(1,1001):
    i=str(i)
    for j in i:
        if int(j)==3:
            cnt+=1
print(cnt)