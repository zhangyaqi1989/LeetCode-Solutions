class Solution:
    def longestArithSeqLength(self, A: List[int]) -> int:
        if len(A) <= 2:
            return len(A)
        ans = 2
        dp = collections.defaultdict(set)
        for i, num in enumerate(A):
            if num in dp:
                for d, cnt in dp.pop(num):
                    dp[num + d].add((d, cnt + 1))
                    ans = max(ans, cnt + 1)
            for j in range(i):
                first = A[j]
                dp[num * 2 - first].add((num - first, 2))
        return ans
