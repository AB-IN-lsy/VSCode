import jieba
xzx = {"什么","一个","我们","那里","你们","如今","说道","知道","这里","姑娘","起来","出来","他们","众人","太太",
            "一面","自己","只见","怎么","奶奶","两个","没有","不是","不知","这个","听见","这样","进来","告诉",
            "就是","咱们","东西","回来","只是","只得","大家","丫头","这些",
            "不敢","出去","所以","不过","的话","不好","姐姐",
            "过来","一时","不能","心里",
            "今日","如此","银子","答应",
            "几个","二人","还有",
            "说话","这么",
            "只管","一回",
            "那边","外头",
            "这话",
            "打发",
            "屋里",
            "自然"}

book = open("红楼梦.txt","r",encoding='utf-8').read()
words = jieba.cut(book)
counts = dict()
for word in words:
    if len(word) == 1:
        continue
    else:
        counts[word] = counts.get(word,0) + 1
for word in xzx:
    del(counts[word])
items = list(counts.items())
items.sort(key = lambda x:x[1],reverse = True)
for i in range(20):
    word,count = items[i]
    print(i + 1,"  {0:<10}{1:>5}".format(word, count))