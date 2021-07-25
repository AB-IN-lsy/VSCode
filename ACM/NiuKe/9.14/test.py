import heapq
data=[1,5,6,8,2,3,4]
lst=[]
for i in data:
    heapq.heappush(lst,i)
print(lst)
