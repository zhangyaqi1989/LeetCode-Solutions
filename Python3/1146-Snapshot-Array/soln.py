class SnapshotArray(object):

    def __init__(self, length):
        """
        :type length: int
        """
        self.nums = [[0] * length]
        self.cnt = 0
        self.curs = [0] * length
        

    def set(self, index, val):
        """
        :type index: int
        :type val: int
        :rtype: None
        """
        self.curs[index] = val
        

    def snap(self):
        """
        :rtype: int
        """
        self.nums.append(self.curs[:])
        self.cnt += 1
        return self.cnt - 1
        

    def get(self, index, snap_id):
        """
        :type index: int
        :type snap_id: int
        :rtype: int
        """
        return self.nums[snap_id + 1][index]


# Your SnapshotArray object will be instantiated and called as such:
# obj = SnapshotArray(length)
# obj.set(index,val)
# param_2 = obj.snap()
# param_3 = obj.get(index,snap_id)
