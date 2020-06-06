class Solution:
    def numsSameConsecDiff(self, N, K):
        """
        :type N: int
        :type K: int
        :rtype: List[int]
        """
        if N == 1:
            return list(range(10))
        else:
            ans = []
            for i in range(1, 10):
                self.helper(N, K, [i], ans)
            return ans
        
    def helper(self, N, K, sub, ans):
        if len(sub) == N:
            num = 0
            for d in sub:
                num = num * 10 + d
            ans.append(num)
        else:
            back = sub[-1]
            for d in set((K, -K)):
                if 0 <= back + d < 10:
                    sub.append(back + d)
                    self.helper(N, K, sub, ans)
                    sub.pop()
