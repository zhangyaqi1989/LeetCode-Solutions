# """
# This is the ArrayReader's API interface.
# You should not implement it, or speculate about its implementation
# """
#class ArrayReader(object):
#	 # Compares 4 different elements in the array
#	 # return 4 if the values of the 4 elements are the same (0 or 1).
#	 # return 2 if three elements have a value equal to 0 and one element has value equal to 1 or vice versa.
#	 # return 0 : if two element have a value equal to 0 and two elements have a value equal to 1.
#    def query(self, a: int, b: int, c: int, d: int) -> int:
#
#	 # Returns the length of the array
#    def length(self) -> int:
#

class Solution:
    def guessMajority(self, reader: 'ArrayReader') -> int:
        n = reader.length()
        a = reader.query(0, 1, 2, 3)
        b = reader.query(0, 1, 2, 4)
        a_cnt = 1
        a_idx = 3
        b_cnt = 0
        b_idx = -1
        for i in range(4, n):
            val = reader.query(0, 1, 2, i)
            if val == a:
                a_cnt += 1
            else:
                b_cnt += 1
                b_idx = i
        for j in range(3):
            idxes = [idx for idx in range(5) if idx != j]
            val = reader.query(*idxes)
            if val == b:
                a_cnt += 1
            else:
                b_cnt += 1
                b_idx = j
        if a_cnt > b_cnt:
            return 3
        elif a_cnt < b_cnt:
            return b_idx
        else:
            return -1
