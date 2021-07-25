'''
Description: file content
Author: NEFU AB_IN
version: 1.0
Date: 2021-07-02 16:43:10
LastEditors: NEFU AB_IN
LastEditTime: 2021-07-02 18:40:04
'''
class heap:
    def __init__(self, lst):
        self.data = lst  # The input list is a list of (key, value) tuples
        self.ptr = {lst[n][0]:n for n in range(len(lst))} # initialize the pointers
        self.size = len(lst)
        for i in range(self.size // 2 - 1, -1, -1):
            self.__heapify(i)
    
    def __len__(self):
        return self.size
    
    def __repr__(self):
        return ', '.join([str(self.data[i]) for i in range(self.size)])
    
    def __heapify(self, i):
        l = 2 * i + 1; # Find the left child of i
        r = 2 * i + 2; # Find the right child of i
        
        # Find the one with smallest values of the three
        smallest_pos = i
        if l < self.size and self.data[l][1] < self.data[smallest_pos][1]:
            smallest_pos = l
        if r < self.size and self.data[r][1] < self.data[smallest_pos][1]:
            smallest_pos = r
            
        # swap if i is not the smallest
        if smallest_pos != i:
            self.data[smallest_pos], self.data[i] = self.data[i], self.data[smallest_pos]
            # change the pointers to the data
            self.ptr[self.data[smallest_pos][0]] = smallest_pos
            self.ptr[self.data[i][0]] = i
            self.__heapify(smallest_pos);
        
    def delete(self):
        if self.size <= 0:
            print('The list is empty!')
            return None
        else:
            min_ele = self.data[0]
            self.data[0] = self.data[self.size-1]
            self.ptr.pop(min_ele[0])
            self.ptr[self.data[0][0]] = 0
            self.size -= 1
            self.__heapify(0)
            return min_ele
    #ptr[0] = 2, means that the data with a key=0 is stored at position 2 
    def decrease_key(self, key, value):
        if key in self.ptr:
            if self.data[self.ptr[key]][1] > value:
                self.data[self.ptr[key]] = (key,value)
                i = self.ptr[key] # get the data position in data array
                # do not sink, because it has smaller value
                while i > 0:
                    p = (i - 1) // 2
                    if self.data[p][1] < self.data[i][1]:
                        break
                    else:
                        self.data[p], self.data[i] =  self.data[i], self.data[p]
                        self.ptr[self.data[p][0]] = p
                        self.ptr[self.data[i][0]] = i
                        i = p
            else:
                print('The new value should be smaller!')
        else:
            print('There is no such a key!')

N = 100
h = [-1 for _ in range(N)]
ne = [0 for _ in range(N)]
e = [0 for _ in range(N)]
w = [0 for _ in range(N)]
idx = 0

def add(a, b, ww):
    global idx
    e[idx] = b
    ne[idx] = h[a]
    w[idx] = ww
    h[a] = idx
    idx += 1


def dijkstra(adj_list, s):
    global h, ne, idx
    color = [0 for _ in range(N)] 
    d = [float('inf') for _ in range(N)]
    for i in range(len(adj_list)):
        for j in adj_list[i]:
            add(i, j, adj_list[i][j])
    d[s] = 0
    paths = [[] for _ in range(N)]
    lst = [(_, d[_]) for _ in range(N)]
    q = heap(lst)
    while len(q):
        ns = q.delete()
        x = ns[0]
        if color[x] == 1:
            continue
        color[x] = 1
        paths[x].append(x)
        i = h[x]
        while i != -1:
            j = e[i]
            if d[j] > d[x] + w[i]:
                d[j] = d[x] + w[i]
                paths[j] = paths[x].copy()
                q.decrease_key(j, d[j])
            i = ne[i]
    for n in range(len(paths)):
        if d[n] == float('inf'):
            paths[n] = None
    h = [-1 for _ in range(N)]
    ne = [0 for _ in range(N)]
    idx = 0
    return d[:len(adj_list)], paths[:len(adj_list)]
    
    
adj_lists = [
    {1:3, 2:1},
    {0:3, 2:7, 3:5, 4:1},
    {0:1, 1:7, 3:2},
    {1:5, 2:2, 4:7},
    {1:1, 3:7}
]

dist, paths = dijkstra(adj_lists, 2)
print(dist)
print(paths)