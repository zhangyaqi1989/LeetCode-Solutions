class LRUCache:

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.capacity = capacity
        self.cache = collections.OrderedDict()
        

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key in self.cache:
            self.cache.move_to_end(key)
            return self.cache[key]
        return -1
        

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        if len(self.cache) < self.capacity or key in self.cache:
            if key in self.cache:
                self.cache.move_to_end(key)
            self.cache[key] = value
        else:
            # evict
            self.cache.popitem(last=False)
            self.cache[key] = value
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)