class Solution:
    def pathSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        tree = {}
        for num in nums:
            D, P, V = map(int, str(num))
            tree[D, P] = V
        self.cnt = 0
        def dfs(D, P, s):
            if (D, P) in tree:
                if (D + 1, P * 2) not in tree and (D + 1, P * 2 - 1) not in tree:
                    self.cnt += s + tree[D, P]
                if (D + 1, P * 2) in tree:
                    dfs(D + 1, P * 2, s + tree[D, P])
                if (D + 1, P * 2 - 1) in tree:
                    dfs(D + 1, P * 2 - 1, s + tree[D, P])
        dfs(1, 1, 0)
        return self.cnt
