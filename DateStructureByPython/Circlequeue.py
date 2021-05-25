class CircularQueue:
    def __init__(self, value = 8):
        self.__items = [None] * value
        self.__front = 0
        self.__back = value - 1
        self.__count = 0
        self.__value = value
    
    def is_empty(self):
        return self.__count == 0
    
    def __str__(self):
        return f"{self.__items}, front:{self.__front}, back:{self.__back}, count:{self.__count}"
    
    def is_full(self):
        return self.__count == self.__value
    
    def enqueue(self, item):
        if self.is_full():
            raise IndexError("ERROR: The queue is full.")
        else:
            self.__back = (self.__back + 1) % self.__value
            self.__items[self.__back] = item
            self.__count += 1
    
    def dequeue(self):
        if self.is_empty():
            raise IndexError("ERROR: The queue is empty.")
        else:
            self.__front = (self.__front + 1) % self.__value
            self.__count -= 1
            return self.__items[self.__front - 1]
    
    def print_all(self):
        cnt = 0
        for _ in range(self.__front, self.__back + self.__value + 1):
            if cnt == self.__count:
                print()
                return
            print(self.__items[_ % self.__value], end = " ")
            cnt += 1
        
