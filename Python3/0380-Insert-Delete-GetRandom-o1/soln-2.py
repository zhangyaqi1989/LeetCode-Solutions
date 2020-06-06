class RandomizedSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.lst = []
        self.size = 0
        self.idxes = {}
        
        

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        """
        if val not in self.idxes:
            self.lst.append(val)
            self.idxes[val] = self.size
            self.size += 1
            return True
        return False
        

    def remove(self, val: int) -> bool:
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        """
        if val in self.idxes:
            idx = self.idxes.pop(val)
            top = self.lst.pop()
            if val != top:
                self.lst[idx] = top
                self.idxes[top] = idx
            self.size -= 1
            return True
        return False
        

    def getRandom(self) -> int:
        """
        Get a random element from the set.
        """
        idx = random.randint(0, self.size - 1)
        return self.lst[idx]
        


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
