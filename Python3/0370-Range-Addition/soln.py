class Solution:
    def getModifiedArray(self, length, updates):
        """
        :type length: int
        :type updates: List[List[int]]
        :rtype: List[int]
        """
        ans = [0] * length
        for start, end, inc in updates:
            ans[start] += inc
            if end + 1 < length:
                ans[end + 1] -= inc
        acc = 0
        for i, num in enumerate(ans):
            acc += num
            ans[i] = acc
        return ans