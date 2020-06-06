class MaxStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.maxes = []
        

    def push(self, x: int) -> None:
        if not self.stack:
            self.maxes.append(x)
        else:
            self.maxes.append(max(x, self.maxes[-1]))
        self.stack.append(x)
        

    def pop(self) -> int:
        self.maxes.pop()
        return self.stack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def peekMax(self) -> int:
        return self.maxes[-1]

    def popMax(self) -> int:
        temp = []
        mx = self.maxes[-1]
        while self.stack[-1] != mx:
            self.maxes.pop()
            temp.append(self.stack.pop())
        self.stack.pop()
        self.maxes.pop()
        for num in reversed(temp):
            self.push(num)
        return mx


# Your MaxStack object will be instantiated and called as such:
# obj = MaxStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.peekMax()
# param_5 = obj.popMax()
