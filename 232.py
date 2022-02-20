class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.instack=deque()
        self.outstack=deque()
        

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.instack.append(x)
        

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        for i in range(len(self.instack)):
            temp=self.instack.pop()
            self.outstack.append(temp)
            
        peek=self.outstack.pop()
        
        for i in range(len(self.outstack)):
            temp=self.outstack.pop()
            self.instack.append(temp)
            
        return peek

    def peek(self) -> int:
        """
        Get the front element.
        """
        for i in range(len(self.instack)):
            temp=self.instack.pop()
            self.outstack.append(temp)
            
        peek=self.outstack[-1]
        
        for i in range(len(self.outstack)):
            temp=self.outstack.pop()
            self.instack.append(temp)
            
        return peek

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        if len(self.instack)==0:
            return True
        else:
            return False


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
