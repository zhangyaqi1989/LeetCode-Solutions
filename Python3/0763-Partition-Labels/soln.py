class Solution:
    def partitionLabels(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        # record its last index and use greedy methods
        m = dict(zip(S, range(len(S))))
        left, right = 0, 0
        res = []
        for idx, ch in enumerate(S):
            right = max(right, m[ch])
            if idx >= right:
                res.append(idx - left + 1)
                left = idx + 1
        return res