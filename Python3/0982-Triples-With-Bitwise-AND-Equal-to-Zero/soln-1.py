class Solution:
    def countTriplets(self, A: List[int]) -> int:
        # 1 <= len(A) <= 1000
        pairs = [0] * (1 << 16)
        for a in A:
            for b in A:
                pairs[a & b] += 1
        ans = 0
        for num in A:
            for p, cnt in enumerate(pairs):
                if cnt and (num & p) == 0:
                    ans += cnt
        return ans
