class Solution:
    def countBits(self, num: int) -> List[int]:
        ans = [0] * (num + 1)
        # 0 1 1 2
        # num - 1
        # lowbit = num & (-num)
        for i in range(1, num + 1):
            lowbit = i & (-i)
            cnt = 0
            while lowbit:
                lowbit >>= 1
                cnt += 1
            ans[i] = ans[i - 1] + 2 - cnt
        return ans
