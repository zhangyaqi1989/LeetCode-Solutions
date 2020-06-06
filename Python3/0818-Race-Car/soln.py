class Solution:
    def __init__(self):
        self.dp = {0 : 0}
        
    def racecar(self, target):
        """
        :type target: int
        :rtype: int
        """
        if target in self.dp:
            return self.dp[target]
        n = target.bit_length()
        if 2 ** n - 1 == target:
            self.dp[target] = n
        else:
            self.dp[target] = self.racecar(2 ** n - 1 - target) + n + 1 # pass the target and return
            for m in range(n - 1):
                self.dp[target] = min(self.dp[target], self.racecar(target - 2 ** (n - 1) + 2 ** m) + m + n + 1)
        return self.dp[target]