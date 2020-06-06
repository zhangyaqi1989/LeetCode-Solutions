class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        if k < 0:
            return 0
        counter = collections.Counter(nums)
        cnt = 0
        for num in counter:
            if (k != 0 and counter[num] and counter[num + k]) or (k == 0 and counter[num] > 1):
                cnt += 1
        return cnt
