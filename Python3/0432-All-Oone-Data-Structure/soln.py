class AllOne:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        # freq -> d
        self.freq_to_dic = collections.defaultdict(set)
        # key_to_freq
        self.freqs = {}
        self.mn = 0
        self.mx = 0
        

    def inc(self, key):
        """
        Inserts a new key <Key> with value 1. Or increments an existing key by 1.
        :type key: str
        :rtype: void
        """
        if key in self.freqs:
            freq = self.freqs[key]
            self.freq_to_dic[freq].remove(key)
        else:
            freq = 0
            self.mn = 1
        if freq == self.mx:
            self.mx += 1
        self.freq_to_dic[freq + 1].add(key)
        self.freqs[key] = freq + 1
        if freq == self.mn and not self.freq_to_dic[freq]:
            self.mn += 1

    def dec(self, key):
        """
        Decrements an existing key by 1. If Key's value is 1, remove it from the data structure.
        :type key: str
        :rtype: void
        """
        if key in self.freqs:
            freq = self.freqs[key]
            self.freq_to_dic[freq].remove(key)
            if freq != 1:
                self.freq_to_dic[freq - 1].add(key)
            self.freqs[key] = freq - 1
            if self.freqs[key] == 0:
                self.freqs.pop(key)
            if freq == self.mn and not self.freq_to_dic[freq]:
                self.mn -= 1
                if self.mn == 0 and self.mx != 0:
                    self.mn = min(self.freqs.values())
            if freq == self.mx and not self.freq_to_dic[freq]:
                self.mx -= 1
        

    def getMaxKey(self):
        """
        Returns one of the keys with maximal value.
        :rtype: str
        """
        return next(iter(self.freq_to_dic[self.mx])) if self.freq_to_dic[self.mx] else ""
        

    def getMinKey(self):
        """
        Returns one of the keys with Minimal value.
        :rtype: str
        """
        return next(iter(self.freq_to_dic[self.mn])) if self.freq_to_dic[self.mn] else ""
        


# Your AllOne object will be instantiated and called as such:
# obj = AllOne()
# obj.inc(key)
# obj.dec(key)
# param_3 = obj.getMaxKey()
# param_4 = obj.getMinKey()
