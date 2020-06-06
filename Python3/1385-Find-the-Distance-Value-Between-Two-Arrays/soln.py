class Solution:
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:
        return sum(all(abs(val1 - val2) > d for val2 in arr2) for val1 in arr1)
