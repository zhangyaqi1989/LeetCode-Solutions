class RandomizedCollection:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.idxes = collections.defaultdict(set)
        self.lst = []
        

    def insert(self, val):
        """
        Inserts a value to the collection. Returns true if the collection did not already contain the specified element.
        :type val: int
        :rtype: bool
        """
        flag = not val in self.idxes
        self.idxes[val].add(len(self.lst))
        self.lst.append(val)
        return flag
        

    def remove(self, val):
        """
        Removes a value from the collection. Returns true if the collection contained the specified element.
        :type val: int
        :rtype: bool
        """
        if val in self.idxes:
            idx = self.idxes[val].pop()
            if not self.idxes[val]:
                self.idxes.pop(val)
            if idx != len(self.lst) - 1:
                self.lst[idx] = self.lst[-1]
                self.idxes[self.lst[-1]].remove(len(self.lst) - 1)
                self.idxes[self.lst[-1]].add(idx)
            self.lst.pop()
            return True
        return False
        

    def getRandom(self):
        """
        Get a random element from the collection.
        :rtype: int
        """
        return random.choice(self.lst)
        


# Your RandomizedCollection object will be instantiated and called as such:
# obj = RandomizedCollection()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()