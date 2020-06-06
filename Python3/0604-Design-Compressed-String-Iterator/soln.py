class StringIterator:

    def __init__(self, compressedString):
        """
        :type compressedString: str
        """
        self.cnt = 0
        self.idx = -1
        self.ch = None
        self.s = compressedString
        

    def next(self):
        """
        :rtype: str
        """
        if self.cnt == 0:
            self.idx += 1
            if self.idx >= len(self.s):
                return ' '
            self.ch = self.s[self.idx]
            j = self.idx + 1
            while j + 1 < len(self.s) and self.s[j + 1].isdigit():
                j += 1
            self.cnt = int(self.s[self.idx + 1:j + 1]) - 1
            self.idx = j
            return self.ch
        else:
            self.cnt -= 1
            return self.ch
        

    def hasNext(self):
        """
        :rtype: bool
        """
        return (self.cnt > 0) or (self.idx + 1) < len(self.s)
        


# Your StringIterator object will be instantiated and called as such:
# obj = StringIterator(compressedString)
# param_1 = obj.next()
# param_2 = obj.hasNext()