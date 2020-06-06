ass Solution:
    def maxSubarraySumCircular(self, A: List[int]) -> int:
        if all(num < 0 for num in A):
            return max(A)
        def helper(func):
            cur = 0
            ans = -40000 if func == max else 40000
            for num in A:
                cur = func(num, cur + num)
                ans = func(ans, cur)
            return ans
        return max(helper(max), sum(A) - helper(min))
