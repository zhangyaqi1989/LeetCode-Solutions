class MaxStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.maxs = []
        

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self.stack.append(x)
        if not self.maxs or x > self.maxs[-1]:
            self.maxs.append(x)
        else:
            self.maxs.append(self.maxs[-1])
        

    def pop(self):
        """
        :rtype: int
        """
        self.maxs.pop()
        return self.stack.pop()
        

    def top(self):
        """
        :rtype: int
        """
        return self.stack[-1]
        
        

    def peekMax(self):
        """
        :rtype: int
        """
        return self.maxs[-1]
        

    def popMax(self):
        """
        :rtype: int
        """
        item = self.maxs.pop()
        b = []
        while self.stack[-1] != item:
            b.append(self.pop())
        self.stack.pop()
        for num in reversed(b):
            self.push(num)
        return item



# Your MaxStack object will be instantiated and called as such:
# obj = MaxStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.peekMax()
# param_5 = obj.popMax()
