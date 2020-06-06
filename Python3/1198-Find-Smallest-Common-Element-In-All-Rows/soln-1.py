class Solution:
    def smallestCommonElement(self, mat: List[List[int]]) -> int:
        counter = collections.Counter()
        m = len(mat)
        for i in range(m - 1):
            for num in mat[i]:
                counter[num] += 1
        for num in mat[-1]:
            counter[num] += 1
            if counter[num] == m:
                return num
        return -1
