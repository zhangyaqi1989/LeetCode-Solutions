class Solution(object):
    def diStringMatch(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        # 0 - N 
        n = len(S)
        nums = list(range(n + 1))
        i, j = 0, len(nums) - 1
        ans = []
        for ch in S:
            if ch == 'I':
                ans.append(nums[i])
                i += 1
            else:
                ans.append(nums[j])
                j -= 1
        ans.append(i)
        return ans