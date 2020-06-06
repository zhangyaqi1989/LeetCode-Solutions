class Solution:
    def uncommonFromSentences(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: List[str]
        """
        counter = collections.Counter(A.split() + B.split())
        return [key for key, cnt in counter.items() if cnt == 1]