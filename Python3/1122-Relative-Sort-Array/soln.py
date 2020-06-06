class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        keys = {num : i for i, num in enumerate(arr2)}  
        arr1.sort(key=lambda x : (keys.get(x, len(arr2)), x))
        return arr1
