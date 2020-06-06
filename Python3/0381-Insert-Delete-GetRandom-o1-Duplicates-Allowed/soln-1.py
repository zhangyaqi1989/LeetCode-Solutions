class RandomizedCollection:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.lst = []
        self.idxes = collections.defaultdict(set)
        

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the collection. Returns true if the collection did not already contain the specified element.
        """
        ans = val not in self.idxes
        self.idxes[val].add(len(self.lst))
        self.lst.append(val)
        return ans
        

    def remove(self, val: int) -> bool:
        """
        Removes a value from the collection. Returns true if the collection contained the specified element.
        """
        # print(self.idxes, self.lst)
        if val in self.idxes:
            idx = self.idxes[val].pop()
            if not self.idxes[val]: 
                self.idxes.pop(val)
            last = self.lst.pop()
            if idx != len(self.lst):
                self.lst[idx] = last
                self.idxes[last].remove(len(self.lst))
                self.idxes[last].add(idx)
            return True
        return False
        

    def getRandom(self) -> int:
        """
        Get a random element from the collection.
        """
        return random.choice(self.lst)
        

# Your RandomizedCollection object will be instantiated and called as such:
# obj = RandomizedCollection()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
