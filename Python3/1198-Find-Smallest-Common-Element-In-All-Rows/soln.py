class Solution:
    def smallestCommonElement(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        inter = set(mat[0])
        for i in range(1, m):
            inter &= set(mat[i])
            if not inter:
                return -1
        return min(inter)
