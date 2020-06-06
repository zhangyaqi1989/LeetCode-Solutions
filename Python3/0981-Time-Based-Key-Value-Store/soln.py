class TimeMap:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.d = collections.defaultdict(list)

    def set(self, key: 'str', value: 'str', timestamp: 'int') -> 'None':
        self.d[key].append((timestamp, value))

    def get(self, key: 'str', timestamp: 'int') -> 'str':
        idx = bisect.bisect_right(self.d[key], (timestamp, 'z' * 100))
        if idx == 0:
            return ""
        else:
            return self.d[key][idx - 1][-1]
        


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
