class TwoSum:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.counter = collections.Counter()
        

    def add(self, number):
        """
        Add the number to an internal data structure..
        :type number: int
        :rtype: void
        """
        self.counter[number] += 1
        

    def find(self, value):
        """
        Find if there exists any pair of numbers which sum is equal to the value.
        :type value: int
        :rtype: bool
        """
        return any ((key == value - key and self.counter[key] > 1) or (key != value - key and self.counter[value - key] > 0) for key in self.counter)
        


# Your TwoSum object will be instantiated and called as such:
# obj = TwoSum()
# obj.add(number)
# param_2 = obj.find(value)