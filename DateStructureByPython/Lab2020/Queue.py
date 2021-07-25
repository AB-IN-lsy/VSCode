class Queue:
    def __init__(self):
        self.__items = []
    
    def get_items(self):
        return self.__items
    
    def is_empty(self):
        return self.__items == []
    
    def enqueue(self, item):
        self.__items.append(item)
    
    def dequeue(self):
        if self.is_empty():
            raise IndexError("ERROR: The queue is empty!")
        else:
            return self.__items.pop(0) 
    
    def size(self):
        return len(self.__items)
    
    def peek(self):
        if self.is_empty():
            raise IndexError("ERROR: The queue is empty!")
        else:
            return self.__items[0]    
    
    def __str__(self):
        return f"Queue: {self.__items}"
    
    def __len__(self):
        return self.size()   
    
    def clear(self):
        self.__items.clear()   
    
    def enqueue_list(self, a_list):
        self.__items += a_list
    
    def multi_dequeue(self, number):
        if self.__len__() < number:
            return False
        else:
            for _ in range(number):
                self.dequeue()
            return True
'''

def mirror_queue(q1):
    q2 = Queue()
    s = Stack()
    while not q1.is_empty():
        tmp = q1.dequeue()
        s.push(tmp)
        q2.enqueue(tmp)
    while not s.is_empty():
        q2.enqueue(s.pop())
    while not q2.is_empty():
        q1.enqueue(q2.dequeue())

def is_palindrome(word):
    q = Queue()
    s = Stack()
    l = ""
    r = ""
    for _ in word:
        q.enqueue(_)
        s.push(_)
    while not q.is_empty():
        l += q.dequeue()
    while not s.is_empty():
        r += s.pop()
    return l == r
'''