def print_all_phrases(d):
    keys=sorted(d.keys())
    for i in d[keys[0]]:
        lst=[i]
        for j in d[keys[1]]:
            lst.append(j)
            for k in d[keys[2]]:
                lst.append(k)
                print(" ".join(lst))
                lst.remove(k)
            lst.remove(j)
        lst.remove(i)