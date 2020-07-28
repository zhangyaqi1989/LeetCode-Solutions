class FirstUnique:

    def __init__(self, nums: List[int]):
        self.counter = collections.Counter(nums)
        self.idx = 0
        self.nums = nums
        

    def showFirstUnique(self) -> int:
        while self.idx < len(self.nums) and self.counter[self.nums[self.idx]] > 1:
            self.idx += 1
        return self.nums[self.idx] if self.idx < len(self.nums) else -1
        
        
    def add(self, value: int) -> None:
        self.nums.append(value)
        self.counter[value] += 1


# Your FirstUnique object will be instantiated and called as such:
# obj = FirstUnique(nums)
# param_1 = obj.showFirstUnique()
# obj.add(value)
