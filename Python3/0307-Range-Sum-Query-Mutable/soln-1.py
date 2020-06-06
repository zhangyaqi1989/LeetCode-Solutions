class NumArray:

    def __init__(self, nums: List[int]):
        self.nums = nums
        self.tree = [0] * (1 + len(nums))
        for i in range(1, len(self.tree)):
            self.add(i, nums[i - 1])
        
    def lowbit(self, x):
        return x & (-x)
    
    def add(self, idx, val):
        while idx < len(self.tree):
            self.tree[idx] += val
            idx += self.lowbit(idx)
            
    def acc(self, idx):
        ans = 0
        while idx > 0:
            ans += self.tree[idx]
            idx -= self.lowbit(idx)
        return ans
    
    def update(self, i: int, val: int) -> None:
        self.add(i + 1, val - self.nums[i])
        self.nums[i] = val

    def sumRange(self, i: int, j: int) -> int:
        return self.acc(j + 1) - self.acc(i)


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(i,val)
# param_2 = obj.sumRange(i,j)
