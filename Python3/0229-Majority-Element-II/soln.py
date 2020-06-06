class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        counter = collections.Counter()
        for num in nums:
            counter[num] += 1
            if len(counter) == 3:
                counter -= collections.Counter(counter.keys())
        return [key for key, cnt in counter.items() if nums.count(key) > len(nums) // 3]