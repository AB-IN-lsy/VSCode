def get_tags_frequency(l):
    l.sort(key=lambda x: x[1])
    d={}
    for i in l:
        try:
            d[i[1]]+=1
        except:
            d.setdefault(i[1],1)
    return d

    