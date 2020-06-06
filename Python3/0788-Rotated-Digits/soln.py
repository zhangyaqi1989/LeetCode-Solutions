class Solution:
    def rotatedDigits(self, N):
        """
        :type N: int
        :rtype: int
        """
        # 0, 1, 8
        # 2 : 5
        # 6 : 9
        def valid(num):
            s = str(num)
            return not any(ch in s for ch in ('3', '4', '7')) and any(ch in s for ch in ('2', '5', '6', '9'))
        return sum(valid(num) for num in range(1, N + 1))