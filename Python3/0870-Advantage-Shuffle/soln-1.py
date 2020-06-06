class Solution:
    def advantageCount(self, A: List[int], B: List[int]) -> List[int]:
        n = len(A)
        order = sorted((b, i) for i, b in enumerate(B))
        ans = [None] * n
        used = [False] * n
        A.sort()
        i = j = 0
        while i < n and j < n:
            while i < n and A[i] <= order[j][0]:
                i += 1
            if i < n:
                used[i] = True
                ans[order[j][1]] = A[i]
                i += 1
                j += 1
        i = 0
        for idx in range(n):
            if ans[idx] is not None:
                continue
            while i < n and used[i]:
                i += 1
            ans[idx] = A[i]
            i += 1
        return ans
