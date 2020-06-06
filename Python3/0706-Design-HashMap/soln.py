class MyHashMap:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.size = 1337
        self.lst  = [[] for _ in range(self.size)]
        

    def put(self, key, value):
        """
        value will always be non-negative.
        :type key: int
        :type value: int
        :rtype: void
        """
        pos = key % self.size
        for pair in self.lst[pos]:
            if pair[0] == key:
                pair[1] = value
                break
        else:
            self.lst[pos].append([key, value])
        

    def get(self, key):
        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        :type key: int
        :rtype: int
        """
        pos = key % self.size
        for k, v in self.lst[pos]:
            if k == key:
                return v
        return -1
        

    def remove(self, key):
        """
        Removes the mapping of the specified value key if this map contains a mapping for the key
        :type key: int
        :rtype: void
        """
        pos = key % self.size
        for i, (k, v) in enumerate(self.lst[pos]):
            if k == key:
                del self.lst[pos][i]
                break
        


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)
