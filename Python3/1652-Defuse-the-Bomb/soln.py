class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        ans = []
        n = len(code)
        for i in range(n):
            val = 0
            if k > 0:
                for j in range(i + 1, i + k + 1):
                    val += code[j % n]
            elif k < 0:
                for j in range(i - 1, i + k - 1, -1):
                    val += code[j]
            ans.append(val)
        return ans
