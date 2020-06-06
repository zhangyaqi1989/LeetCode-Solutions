class LFUCache:

    def __init__(self, capacity: int):
        # how to do this in O(1)
        self.capacity = capacity
        self.freqs = collections.Counter() # map key to counts
        self.freqs_d = collections.defaultdict(collections.OrderedDict) # map freq to (key, value) pairs
        self.mn_freq = 0

    def get(self, key: int) -> int:
        if key not in self.freqs:
            return -1
        freq = self.freqs[key]
        value = self.freqs_d[freq][key]
        self.freqs_d[freq].pop(key)
        if freq == self.mn_freq and not self.freqs_d[freq]:
            self.mn_freq = freq + 1 
        freq += 1
        self.freqs[key] = freq
        self.freqs_d[freq][key] = value
        return value

    def put(self, key: int, value: int) -> None:
        if not self.capacity:
            return
        freq = self.freqs[key]
        if freq == 0 and len(self.freqs) == self.capacity:
            remove_key, _ = self.freqs_d[self.mn_freq].popitem(last=False)
            self.freqs.pop(remove_key)
            if self.capacity == 1:
                self.mn_freq = 0
            else:
                while not self.freqs_d[self.mn_freq]:
                    self.mn_freq += 1
        self.freqs[key] += 1
        if freq != 0:
            self.freqs_d[freq].pop(key)
        if freq == 0:
            self.mn_freq = 1
        self.freqs_d[freq + 1][key] = value
        if self.mn_freq == freq and not self.freqs_d[freq]:
            self.mn_freq = freq + 1

# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
