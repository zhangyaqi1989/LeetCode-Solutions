class MyCircularDeque:

    def __init__(self, k: int):
        """
        Initialize your data structure here. Set the size of the deque to be k.
        """
        self.nums = [0] * k
        self.k = k
        self.size = 0
        self.front = -1
        self.back = 0
        

    def insertFront(self, value: int) -> bool:
        """
        Adds an item at the front of Deque. Return true if the operation is successful.
        """
        if not self.isFull():
            self.size += 1
            self.front = (self.front + 1) % self.k
            self.nums[self.front] = value
            return True
        else:
            return False
        

    def insertLast(self, value: int) -> bool:
        """
        Adds an item at the rear of Deque. Return true if the operation is successful.
        """
        if not self.isFull():
            self.size += 1
            self.back -= 1
            if self.back < 0:
                self.back += self.k
            self.nums[self.back] = value
            return True
        else:
            return False
        

    def deleteFront(self) -> bool:
        """
        Deletes an item from the front of Deque. Return true if the operation is successful.
        """
        if not self.isEmpty():
            self.size -= 1
            self.front = self.front - 1
            if self.front < 0:
                self.front += self.k
            return True
        else:
            return False
        

    def deleteLast(self) -> bool:
        """
        Deletes an item from the rear of Deque. Return true if the operation is successful.
        """
        if not self.isEmpty():
            self.size -= 1
            self.back = (self.back + 1) % self.k
            return True
        else:
            return False
        

    def getFront(self) -> int:
        """
        Get the front item from the deque.
        """
        return self.nums[self.front] if not self.isEmpty() else -1
        

    def getRear(self) -> int:
        """
        Get the last item from the deque.
        """
        return self.nums[self.back] if not self.isEmpty() else -1
        

    def isEmpty(self) -> bool:
        """
        Checks whether the circular deque is empty or not.
        """
        return not self.size
        

    def isFull(self) -> bool:
        """
        Checks whether the circular deque is full or not.
        """
        return self.size == self.k
        


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()
