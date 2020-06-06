class Solution:
    def tallestBillboard(self, rods: List[int]) -> int:
        dp = {0 : 0}
        for rod in rods:
            temp = collections.defaultdict(int)
            for key, value in dp.items():
                temp[key + rod] = max(temp[key + rod], dp[key] + rod)
                temp[key] = max(temp[key], dp[key])
                temp[key - rod] = max(temp[key - rod], dp[key])
            dp = temp
        return dp[0]
