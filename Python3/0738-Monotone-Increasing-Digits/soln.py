class Solution:
    def monotoneIncreasingDigits(self, N):
        """
        :type N: int
        :rtype: int
        """
        if N < 10: return N
        # 1343 ---> 1339
        # 13443 ---> 13439
        nums = list(map(int, str(N)))
        n = len(nums)
        for i in range(0, n - 1):
            if nums[i] > nums[i + 1]:
                break
        else:
            return N
        idx = i
        while idx >= 0 and nums[idx] == nums[i]:
            idx -= 1
        idx += 1
        for j in range(idx + 1, n):

            nums[j] = 9
        nums[idx] -= 1
        return int(''.join(map(str, nums)))
