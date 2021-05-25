d=dict()
#d={'black':0,'blue':0,'green':0,'red':0,'white':0,'yellow':0}
while True:
    try:
        s=input()
        if s=="#":
            break
        else:
            try:
                d[s]+=1
            except:
                d.setdefault(s,1)
    except:
        break
a=sorted(d.items())
for i in a:
    print(i[0],i[1])
