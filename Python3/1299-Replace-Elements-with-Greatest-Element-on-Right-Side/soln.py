class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        right = -1
        n = len(arr)
        for i in reversed(range(n)):
            arr[i], right = right, max(right, arr[i])
        return arr
