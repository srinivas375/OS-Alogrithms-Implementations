class Node:
    def __init__(self,data) -> None:
        self.data = data
        self.next = None

class linked_list:
    def __init__(self) -> None:
        self.head = None
        self.count = 0
        self.hit = 0
        self.miss = 0
    
    def enqueue(self,data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return 
        current = self.head 
        while current.next: 
            current = current.next  
        current.next = new_node #type: ignore
        
    def operation(self,data):
        if self.check():
            if self.search(data):
                print("hit...")
                self.hit += 1
            else:
                print("miss...")
                self.miss += 1
                self.enqueue(data)
            self.count += 1
        else:
            if self.search(data):
                print("hit...")
                self.hit += 1
            else:
                print("miss...")
                self.miss += 1
                self.enqueue(data)
                self.dequeue()
        self.display(data)
            
    def display(self,data):
        current = self.head
        while current:
            print(current.data,end="->")
            current = current.next
        print("None")
        
    def dequeue(self):
        self.head = self.head.next #type:ignore
    
    def check(self):
        if(self.count == self.size):#type: ignore
            return 0
        return 1 
    
    def search(self,data):
        current = self.head
        while current:
            if current.data == data:
                return 1
            current = current.next
        return 0
            
obj = linked_list()
obj.size = int(input("enter the size of the queue :")) #type: ignore
n = int(input("enter number of pages :"))
for i in range(n):
    data = int(input("enter page frame {} :".format(i+1)))
    obj.operation(data)
print("total number of hits are :",obj.hit)
print("total number of misses are :",obj.miss)
print("hit ratio is :",obj.hit/n)    