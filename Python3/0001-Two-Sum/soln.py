class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        need = {}
        for idx, num in enumerate(nums):
            if num in need:
                return need[num], idx
            need[target - num] = idx

if __name__ == '__main__':
    solution = Solution()
    print(solution.twoSum([2, 7, 11, 15], 9))
