s=input("Enter a sentence: ").strip().split()
d={}
for i in s:
    try:
        i=i.lower()
        if i not in d[len(i)]:
            d[len(i)].append(i)
    except:
        d.setdefault(len(i),[i])
for i in sorted(d.keys()):
        print(i," ".join(sorted(d[i])))