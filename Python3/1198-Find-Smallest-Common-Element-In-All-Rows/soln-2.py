class Solution:
    def smallestCommonElement(self, mat: List[List[int]]) -> int:
        dp = [0] * 10001
        m = len(mat)
        for row in mat:
            for num in row:
                dp[num] += 1
                if dp[num] == m:
                    return num
        return -1
