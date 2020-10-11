class Solution:
    def specialArray(self, nums: List[int]) -> int:
        for x in range(1001):
            cnt = sum(num >= x for num in nums)
            if cnt == x:
                return x
        return -1
