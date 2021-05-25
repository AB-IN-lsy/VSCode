def getkey(x):
    return (x[2],x[0],x[1])
lst=list()#list[]是个空列表
while True:
    try:
        tmp=list(map(int,input().split('/')))
    except:
        break#承接着except的else
    lst.append(tmp)
lst.sort(key=getkey)#x为接受的参数(即列表中的值)，冒号后面为结果
#1.按升序排的。2.按先排x[2] 再排x[0] 再排x[1]。
for i in lst:
    i=[str(j) for j in i]
    if len(i[0])==1:
        i[0]="0"+i[0]
    print("/".join(i))


