class Solution:
    def checkRecord(self, s: str) -> bool:
        # A L P
        return s.count('A') <= 1 and 'LLL' not in s 
