class Solution:
    def checkValidString(self, s: str) -> bool:
        lo = hi = 0
        for ch in s:
            if ch == '(':
                lo += 1
                hi += 1
            elif ch == '*':
                hi += 1
                lo -= 1
            else:
                lo -= 1
                hi -= 1
            lo = max(0, lo)
            if hi < 0:
                return False
        return lo == 0
