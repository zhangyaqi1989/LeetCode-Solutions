class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        ans = []
        for num in arr:
            if num:
                ans.append(num)
            else:
                ans.extend([0, 0])
        n = len(arr)
        arr[:n] = ans[:n]
