class PriorityQueue:
    def __init__(self):
        self.__binary_heap = [0]
        self.__size =  0
    def __str__(self):
        return f"{self.__binary_heap}"
    def __len__(self):
        return self.__size
    def add_all(self, a_list):
        self.__binary_heap += a_list
        self.__size += len(a_list)
    def percolate_up(self, i):
        while i // 2:
            if self.__binary_heap[i] < self.__binary_heap[i // 2]:
                self.__binary_heap[i], self.__binary_heap[i // 2] = self.__binary_heap[i // 2], self.__binary_heap[i]
            i = i // 2
    def insert(self, element):
        self.__binary_heap.append(element)
        self.__size += 1
        self.percolate_up(self.__size)
    def get_smaller_child_index(self, index):
        if index * 2 + 1> self.__size:
            return index * 2 
        else:
            return self.__binary_heap.index(min(self.__binary_heap[index * 2], self.__binary_heap[index * 2 + 1]))
    def percolate_down(self, i):
        while (i * 2) <= self.__size:
                s_c = self.get_smaller_child_index(i)
                if self.__binary_heap[i] > self.__binary_heap[s_c]:
                    self.__binary_heap[i], self.__binary_heap[s_c] = self.__binary_heap[s_c], self.__binary_heap[i]
                i = s_c
    def create_heap_fast(self, values):
        self.add_all(values)
        for _ in range(self.__size, 0, -1):
            self.percolate_down(_)
        return self.__binary_heap
    def delete_minimum(self):
        minimum_value = self.__binary_heap[1]
        self.__binary_heap[1] = self.__binary_heap[self.__size]
        self.__size = self.__size - 1
        self.__binary_heap.pop()
        self.percolate_down(1)
        return minimum_value

def heap_sort(values):
    lst = []
    q = PriorityQueue()
    for _ in values:
        q.insert(_)
    while q.__len__():
        lst.append(q.delete_minimum())
    return lst

result = heap_sort([45, 21, 87, 66, 94, 17, 13, 58, 32, 57, 81, 50])
print(result)