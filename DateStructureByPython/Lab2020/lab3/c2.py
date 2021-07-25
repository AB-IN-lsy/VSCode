
def get_tag_words(line):
    a,b=line.strip().split(":")
    l=list()
    l.append(a)
    l.append(b.split())
    return tuple(l)

line='CD:five one seven'
print(get_tag_words(line))