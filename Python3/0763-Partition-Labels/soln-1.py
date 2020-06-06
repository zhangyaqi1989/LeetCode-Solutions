class Solution:
    def partitionLabels(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        idxes = dict(zip(S, range(len(S))))
        ans, left, right = [], 0, 0
        for i, ch in enumerate(S):
            right = max(right, idxes[ch])
            if right == i:
                ans.append(right - left + 1)
                left = right = i + 1
        return ans