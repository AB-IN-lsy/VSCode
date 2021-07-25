'''
Description: file content
Author: NEFU AB_IN
version: 1.0
Date: 2021-07-02 08:03:10
LastEditors: NEFU AB_IN
LastEditTime: 2021-07-02 15:20:21
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
        
            
h = heap([(0, 5),(1, 2),(2, 4),(3, 3),(4, 1)])
print(h)
h.decrease_key(3, 0)
print(h)
print(h.delete())
print(h)