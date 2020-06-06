class Solution:
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        # needs to understand how to generate grey code
        if n <= 0: return [0]
        ans = ['0', '1']
        for _ in range(n - 1):
            ans = ['0' + item for item in ans] + ['1' + item for item in ans[::-1]]
        return [int(item, 2) for item in ans]