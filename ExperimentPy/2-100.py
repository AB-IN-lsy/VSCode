for i in range(2,101):
    for j in range(2,i+1):
        if i%j==0:
            break
    if j==i:
        print(i,end=" ")
