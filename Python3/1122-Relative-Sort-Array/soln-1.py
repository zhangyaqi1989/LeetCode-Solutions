class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        d = {num : i for i, num in enumerate(arr2)}
        return sorted(arr1, key=lambda a : (d.get(a, 4000), a))
