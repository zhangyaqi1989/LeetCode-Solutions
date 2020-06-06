class Solution:
    def canTransform(self, start, end):
        """
        :type start: str
        :type end: str
        :rtype: bool
        """
        s = [(ch, idx) for idx, ch in enumerate(start) if ch in ('L', 'R')]
        e = [(ch, idx) for idx, ch in enumerate(end) if ch in ('L', 'R')]
        return len(s) == len(e) and all(ch1 == ch2 and ((ch1 == 'L' and idx1 >= idx2) or (ch1 == 'R' and idx2 >= idx1)) for (ch1, idx1), (ch2, idx2) in zip(s, e))