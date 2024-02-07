class Stack:
    def __init__(self, size):
        self.maxSize = size
        self.pointer = -1 
        self.data = []
    
    def peek(self):
        print(self.data[self.pointer])

    def push(self, element):
        if self.pointer > self.maxSize:
            exit(1)
        else:
            self.data.append(element)
            self.pointer = self.pointer + 1

    def pop(self):
        self.data.pop()
        self.pointer = self.pointer - 1 

    def isfull(self):
        if len(self.data) == self.maxSize:
            return True
        else:
            return False
    
    def isempty(self):
        if len(self.data) == 0:
            return True
        else:
            return False

    
mystack = Stack(10)

myinternalstack = Stack(10)

for i in range(10):
    myinternalstack.push("hello")


for i in range(10):
    mystack.push(myinternalstack)

mystack.peek()


