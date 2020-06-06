class RandomizedSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.indexes = {}
        self.lst = []
        

    def insert(self, val):
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        :type val: int
        :rtype: bool
        """
        if val not in self.indexes:
            self.indexes[val] = len(self.lst)
            self.lst.append(val)
            return True
        return False
        

    def remove(self, val):
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        :type val: int
        :rtype: bool
        """
        if val in self.indexes:
            idx = self.indexes.pop(val)
            if idx != len(self.lst) - 1:
                self.indexes[self.lst[-1]] = idx
                self.lst[idx] = self.lst[-1]
            self.lst.pop()
            return True
        return False
        
        
        

    def getRandom(self):
        """
        Get a random element from the set.
        :rtype: int
        """
        return random.choice(self.lst)
        


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()