class Solution:
    def isPossible(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        # # greedy algorithm
        left = collections.Counter(nums)
        end = collections.Counter()
        for num in nums:
            if not left[num]:
                continue
            left[num] -= 1
            if end[num - 1] > 0:
                end[num - 1] -= 1
                end[num] += 1
            elif left[num + 1] and left[num + 2]:
                left[num + 1] -= 1
                left[num + 2] -= 1
                end[num + 2] += 1
            else:
                return False
        return True