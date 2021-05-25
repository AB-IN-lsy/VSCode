class Node:
    def __init__(self, data, nxt):
        self.data = data
        self.nxt = nxt
#链表模拟队列
class linklist_queue:
    def __init__(self):
        self.head = None # 头地址为None
    def enqueue(self, data):
        if self.head == None: # 如果头地址为None，说明链表里没有元素，所以直接放一个Node即可，nxt = None
            self.head = Node(data, None)
        else:
            current = self.head # 不然的话就顺着地址找最后的Node，并且将最后的Node的地址赋为 新的Node
            while current.nxt != None:
                current = current.nxt
            current.nxt = Node(data, None)
    def dequeue(self):
        if self.head == None: # 如果头地址为None，说明链表里没有元素，不用弹出元素
            return None
        else:
            data = self.head.data #第一个Node就是需要弹出的。如何弹出？
            self.head = self.head.nxt # 就是将头地址指向第二个Node（即指向第一个Node里存的地址），这样第一个元素自动删除
            return data

queue = linklist_queue()
queue.enqueue(1)
queue.enqueue(2)
queue.enqueue(3)
print(queue.dequeue())
print(queue.dequeue())
print(queue.dequeue())
print(queue.dequeue())

class linklist_stack:
    def __init__(self):
        self.head = None
    def push(self, data):
        self.head = Node(data, self.head)
    def pop(self):
        if self.head == None: 
            return None
        else:
            data = self.head.data
            self.head = self.head.nxt
            return data

stack = linklist_stack()
stack.push(1)
stack.push(2)
stack.push(3)
print(stack.pop())
print(stack.pop())
print(stack.pop())
print(stack.pop())

#升序排序
def print_list(head):
    current = head
    while current != None:
        print(current.data)
        current = current.nxt
def insert_in_place(head, value):
    node = Node(value, None) #先创建一个单元
    if head == None:
        return node
    else:
        previous = None
        current = head
        while current != None and current.data < value:
            previous = current
            current = current.nxt
        node.nxt = current # 找到位置了，就将node连向下一个
        if previous != None:
            previous.nxt = node #说明前头有连着的，所以要连上
            return head #此时头地址还是head
        else:
            return node #说明前头没有连着的，这时候这个node就是头地址
top = Node(5, None)
top = insert_in_place(top, 4)
top = insert_in_place(top, 6)
top = insert_in_place(top, 7)
top = insert_in_place(top, 8)
top = insert_in_place(top, 2)
print_list(top)