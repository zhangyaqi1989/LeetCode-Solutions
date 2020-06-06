class Solution:
    def canTransform(self, start, end):
        """
        :type start: str
        :type end: str
        :rtype: bool
        """
        s_idxes = [(ch, idx) for idx, ch in enumerate(start) if ch in 'LR']
        e_idxes = [(ch, idx) for idx, ch in enumerate(end) if ch in 'LR']
        return len(start) == len(end) and len(s_idxes) == len(e_idxes) and all(ch1 == ch2 and ((ch1 == 'L' and idx2 <= idx1) or (ch1 == 'R' and idx2 >= idx1)) for (ch1, idx1), (ch2, idx2) in zip(s_idxes, e_idxes))