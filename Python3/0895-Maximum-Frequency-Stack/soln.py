class FreqStack:

    def __init__(self):
        self.freq = collections.Counter()
        self.stacks = collections.defaultdict(list)
        self.mx_freq = 0
        

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self.freq[x] += 1
        if self.freq[x] > self.mx_freq:
            self.mx_freq = self.freq[x]
        self.stacks[self.freq[x]].append(x)
        

    def pop(self):
        """
        :rtype: int
        """
        x = self.stacks[self.mx_freq].pop()
        if not self.stacks[self.mx_freq]:
            self.mx_freq -= 1
        self.freq[x] -= 1
        return x
        


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(x)
# param_2 = obj.pop()
