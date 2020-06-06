class Solution:
    def pathSum(self, nums: List[int]) -> int:
        # 1 <= D <= 4
        if not nums:
            return 0
        def parse(num):
            "return D, P, V"
            return list(map(int, str(num)))
        tree = {}
        for D, P, V in map(parse, nums):
            tree[D, P] = V
        self.ans = 0
        def dfs(D, P, path):
            if (D + 1, 2 * P - 1) not in tree and (D + 1, 2 * P) not in tree:
                self.ans += (path + tree[D, P])
            else:
                if (D + 1, 2 * P - 1) in tree:
                    dfs(D + 1, 2 * P - 1, path + tree[D, P])
                if (D + 1, 2 * P) in tree:
                    dfs(D + 1, 2 * P, path + tree[D, P])
        dfs(1, 1, 0)
        return self.ans
