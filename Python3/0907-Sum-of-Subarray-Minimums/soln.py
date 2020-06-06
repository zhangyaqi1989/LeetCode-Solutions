class Solution(object):
    def sumSubarrayMins(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        # A = [3, 1, 2, 4]
        stack = []
        res = 0
        A = [float('-inf')] + A + [float('-inf')]
        for i, num in enumerate(A):
            while stack and A[stack[-1]] > num:
                cur = stack.pop()
                res += A[cur] * (cur - stack[-1]) * (i - cur)
            stack.append(i)
        return res % (10 ** 9 + 7)
