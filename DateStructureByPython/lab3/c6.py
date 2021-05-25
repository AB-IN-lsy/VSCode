def get_tag_tuple_list(d, s):
    lst=[]
    l=sorted(s.lower().split())
    for i in l:
        for keys in d:
            t=[]
            if i in d[keys]:
                t.extend([i,keys])
            if tuple(t) not in lst and t:
                lst.append(tuple(t))
                break
    return lst
tags_dictionary={'VBZ':['is'],'DT':['the']}
print(get_tag_tuple_list(tags_dictionary, 'Summer is over and the hot days are gone The grass is brown'))
