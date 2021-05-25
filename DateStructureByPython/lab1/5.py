lst=[]
for i in range(200,301):
    if i%5==0 and i%3!=0:
        lst.append(str(i))
print(",".join(lst))
