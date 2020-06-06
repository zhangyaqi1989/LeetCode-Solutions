class Solution:
    def minDominoRotations(self, A: List[int], B: List[int]) -> int:
        cands = set((A[0], B[0]))
        n = len(A)
        for i in range(1, n):
            cands = cands & set((A[i], B[i]))
            if not cands:
                return -1
        ans = n
        for cand in cands:
            temp = min(sum(item != cand for item in A), sum(item != cand for item in B))
            if temp < ans:
                ans = temp
        return ans
