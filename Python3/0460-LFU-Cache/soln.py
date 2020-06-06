class LFUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.capacity = capacity
        self.list_dict = collections.defaultdict(collections.OrderedDict) # map fre --> ordereddict
        self.fre_dict = {} # map key --> frequency
        self.min_fre = 1
        

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        # Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
        if key in self.fre_dict:
            fre = self.fre_dict[key]
            val = self.list_dict[fre].pop(key)
            self.list_dict[fre + 1][key] = val
            self.fre_dict[key] = fre + 1
            if len(self.list_dict[fre]) == 0 and self.min_fre == fre:
                self.min_fre += 1
            return val
        return -1
        

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        if self.capacity == 0:
            return
        if len(self.fre_dict) < self.capacity or (len(self.fre_dict) == self.capacity and key in self.fre_dict):
            if key not in self.fre_dict:
                self.fre_dict[key] = 1
                self.min_fre = 1
                self.list_dict[1][key] = value
            else:
                fre = self.fre_dict[key]
                self.list_dict[fre].pop(key)
                self.list_dict[fre + 1][key] = value
                self.fre_dict[key] = fre + 1
                if len(self.list_dict[fre]) == 0 and self.min_fre == fre:
                    self.min_fre += 1
        else: # maximum capacity reached and key not dict
            # evict
            temp = self.list_dict[self.min_fre].popitem(last=False)
            self.fre_dict.pop(temp[0])
            self.fre_dict[key] = 1
            self.list_dict[1][key] = value
            self.min_fre = 1
           

# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)