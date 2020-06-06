class Solution:

    def __init__(self, nums: List[int]):
        # map target to idxes
        self.idxes = collections.defaultdict(list)
        for i, num in enumerate(nums):
            self.idxes[num].append(i)

    def pick(self, target: int) -> int:
        return random.choice(self.idxes[target])
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)
