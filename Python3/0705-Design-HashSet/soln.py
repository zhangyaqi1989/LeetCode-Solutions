class MyHashSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.size = 1337
        self.lst  = [[] for _ in range(self.size)]
        

    def add(self, key):
        """
        :type key: int
        :rtype: void
        """
        pos = key % self.size
        if key not in self.lst[pos]:
            self.lst[pos].append(key)
        

    def remove(self, key):
        """
        :type key: int
        :rtype: void
        """
        pos = key % self.size
        try:
            self.lst[pos].remove(key)
        except:
            pass
        

    def contains(self, key):
        """
        Returns true if this set contains the specified element
        :type key: int
        :rtype: bool
        """
        pos = key % self.size
        return key in self.lst[pos]
        


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
