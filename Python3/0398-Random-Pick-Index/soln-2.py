class Solution:

    def __init__(self, nums: List[int]):
        self.nums = nums

    def pick(self, target: int) -> int:
        cnt, idx = 0, 0
        for i, num in enumerate(self.nums):
            if num == target:
                rand = random.randint(0, cnt)
                if rand == 0:
                    idx = i
                cnt += 1
        return idx


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)
