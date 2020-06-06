class MyCircularQueue:

    def __init__(self, k):
        """
        Initialize your data structure here. Set the size of the queue to be k.
        :type k: int
        """
        self.lst = [0] * k
        self.k = k
        self.front = 0
        self.back = 0
        self.size = 0
        

    def enQueue(self, value):
        """
        Insert an element into the circular queue. Return true if the operation is successful.
        :type value: int
        :rtype: bool
        """
        if self.size < self.k:
            self.lst[self.back] = value
            self.back = (self.back + 1) % self.k
            self.size += 1
            return True
        return False
            
        

    def deQueue(self):
        """
        Delete an element from the circular queue. Return true if the operation is successful.
        :rtype: bool
        """
        if self.size > 0:
            self.front = (self.front + 1) % self.k
            self.size -= 1
            return True
        return False
            
        

    def Front(self):
        """
        Get the front item from the queue.
        :rtype: int
        """
        return self.lst[self.front] if not self.isEmpty() else -1
        

    def Rear(self):
        """
        Get the last item from the queue.
        :rtype: int
        """
        return self.lst[(self.back - 1) % self.k] if not self.isEmpty() else -1
        

    def isEmpty(self):
        """
        Checks whether the circular queue is empty or not.
        :rtype: bool
        """
        return self.size == 0
        

    def isFull(self):
        """
        Checks whether the circular queue is full or not.
        :rtype: bool
        """
        return self.size == self.k
        


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()
