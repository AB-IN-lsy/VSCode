def word_len_frequencies(s):
    d={}
    lst=[i.lower() for i in s.split()]
    for i in lst:
        cnt=lst.count(i)
        try:
            if i not in d[cnt]:
                d[cnt].append(i)
        except:
            d.setdefault(cnt,[i])
    for i in sorted(d.keys(),reverse=True):
        print(i,sorted(d[i]))
word_len_frequencies('this is a really long sentence of words and there will be some repeated words in this really long sentence of words')
