class Solution:
    def pancakeSort(self, A: List[int]) -> List[int]:
        # reverse the order of first k elements
        if A == sorted(A):
            return []
        ans = []
        n = len(A)
        for top in reversed(range(1, n + 1)):
            idx = A.index(top)
            if idx == top - 1:
                continue
            ans.append(idx + 1)
            A[0:idx + 1] = A[0:idx + 1][::-1]
            ans.append(top)
            A[0:top] = A[0:top][::-1]
        return ans
