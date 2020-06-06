class NumArray:

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.tree = [0] * (len(nums) + 1)
        self.nums = [0] * len(nums)
        self.size = len(nums)
        for i in range(len(nums)):
            self.update(i, nums[i])
        

    def update(self, i, val):
        """
        :type i: int
        :type val: int
        :rtype: void
        """
        diff = val - self.nums[i]
        self.nums[i] = val
        i = i + 1
        while i <= self.size:
            self.tree[i] += diff
            i += i & (-i)
            
    def getSum(self, i):
        ans = 0
        i = i + 1
        while i > 0:
            ans += self.tree[i]
            i -= i & (-i)
        return ans
        
        

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        if i == 0: return self.getSum(j)
        return self.getSum(j) - self.getSum(i - 1)
        


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(i,val)
# param_2 = obj.sumRange(i,j)