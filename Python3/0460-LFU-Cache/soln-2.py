class LFUCache:

    def __init__(self, capacity: int):
        self.freqs = collections.Counter()
        self.mn_freq = 0
        self.capacity = capacity
        self.freq_d = collections.defaultdict(collections.OrderedDict)

    def get(self, key: int) -> int:
        if key in self.freqs:
            freq = self.freqs[key]
            self.freqs[key] += 1
            value = self.freq_d[freq].pop(key)
            self.freq_d[freq + 1][key] = value
            if self.mn_freq == freq and not self.freq_d[freq]:
                self.mn_freq += 1
            return value
        else:
            return -1
        

    def put(self, key: int, value: int) -> None:
        if not self.capacity:
            return
        if len(self.freqs) < self.capacity or key in self.freqs: # no evict
            if key in self.freqs:
                freq = self.freqs[key]
                self.freqs[key] += 1
                self.freq_d[freq].pop(key)
                self.freq_d[freq + 1][key] = value
                if freq == self.mn_freq and not self.freq_d[freq]:
                    self.mn_freq += 1
            else:
                self.freqs[key] = 1
                self.mn_freq = 1
                self.freq_d[1][key] = value
        else:
            # first evict
            remove, _ = self.freq_d[self.mn_freq].popitem(last=False)
            self.freqs.pop(remove)
            # then add
            self.freqs[key] = 1
            self.mn_freq = 1
            self.freq_d[1][key] = value
        # print(self.freqs)
            

# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
