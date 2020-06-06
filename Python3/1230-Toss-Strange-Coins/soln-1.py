class Solution:
    def probabilityOfHeads(self, prob: List[float], target: int) -> float:
        n = len(prob)
        dp = [1] + [0] * (target)
        for i in range(n):
            temp = [0] * (target + 1)
            head = prob[i]
            tail = 1 - head
            temp[0] = dp[0] * tail
            for j in range(1, min(target + 1, i + 2)):
                temp[j] = dp[j] * tail + dp[j - 1] * head
            dp = temp
        return dp[target]
