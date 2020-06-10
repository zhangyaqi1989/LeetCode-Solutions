class Solution:
    def numberOfSteps (self, num: int) -> int:
        cnt = 0
        while num:
            cnt += 1
            if num & 1:
                num -= 1
            else:
                num >>= 1
        return cnt
