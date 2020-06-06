class Solution:
    def largeGroupPositions(self, S):
        """
        :type S: str
        :rtype: List[List[int]]
        """
        return [[m.start(), m.end() - 1] for m in re.finditer(r'(\w)\1{2,}', S)]