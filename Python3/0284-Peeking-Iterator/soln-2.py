# Below is the interface for Iterator, which is already defined for you.
#
# class Iterator:
#     def __init__(self, nums):
#         """
#         Initializes an iterator object to the beginning of a list.
#         :type nums: List[int]
#         """
#
#     def hasNext(self):
#         """
#         Returns true if the iteration has more elements.
#         :rtype: bool
#         """
#
#     def next(self):
#         """
#         Returns the next element in the iteration.
#         :rtype: int
#         """

class PeekingIterator:
    def __init__(self, iterator):
        """
        Initialize your data structure here.
        :type iterator: Iterator
        """
        self.iter = iterator
        self.valid = False
        self.next_val = None
        
        
    def update_next(self):
        if not self.valid:
            self.valid = self.iter.hasNext()
            if self.valid:
                self.next_val = self.iter.next()
        

    def peek(self):
        """
        Returns the next element in the iteration without advancing the iterator.
        :rtype: int
        """
        self.update_next()
        return self.next_val
        

    def next(self):
        """
        :rtype: int
        """
        self.update_next()
        val = self.next_val
        self.next_val = None
        self.valid = False
        return val
        

    def hasNext(self):
        """
        :rtype: bool
        """
        self.update_next()
        return self.valid
        

# Your PeekingIterator object will be instantiated and called as such:
# iter = PeekingIterator(Iterator(nums))
# while iter.hasNext():
#     val = iter.peek()   # Get the next element but not advance the iterator.
#     iter.next()         # Should return the same value as [val].
