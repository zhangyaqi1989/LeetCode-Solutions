class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        def helper(cur):
            if cur > n:
                return
            ans.append(cur)
            helper(cur * 10)
            if cur % 10 != 9:
                helper(cur + 1)
        ans = []
        helper(1)
        return ans
