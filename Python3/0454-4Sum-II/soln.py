class Solution:
    def fourSumCount(self, A, B, C, D):
        """
        :type A: List[int]
        :type B: List[int]
        :type C: List[int]
        :type D: List[int]
        :rtype: int
        """
        def build_two_sum(A, B):
            two_sum = collections.Counter()
            for i, a in enumerate(A):
                for j, b in enumerate(B):
                    two_sum[a + b] += 1
            return two_sum
        two_sum1 = build_two_sum(A, B)
        two_sum2 = build_two_sum(C, D)
        ans = 0
        for num, cnt in two_sum1.items():
            if -num in two_sum2:
                ans += cnt * two_sum2[-num]
        return ans
