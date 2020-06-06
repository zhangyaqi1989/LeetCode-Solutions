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
        self.iterator = iterator
        self.peek_val = None
        self.valid = False
        
    def _updatePeek(self):
        if not self.valid:
            if self.iterator.hasNext():
                self.valid = True
                self.peek_val = self.iterator.next()
            else:
                self.peek_val = None
        

    def peek(self):
        """
        Returns the next element in the iteration without advancing the iterator.
        :rtype: int
        """
        self._updatePeek()
        return self.peek_val

    def next(self):
        """
        :rtype: int
        """
        self._updatePeek()
        self.valid = False
        return self.peek_val
        

        

    def hasNext(self):
        """
        :rtype: bool
        """
        self._updatePeek()
        return self.valid
        

# Your PeekingIterator object will be instantiated and called as such:
# iter = PeekingIterator(Iterator(nums))
# while iter.hasNext():
#     val = iter.peek()   # Get the next element but not advance the iterator.
#     iter.next()         # Should return the same value as [val].
