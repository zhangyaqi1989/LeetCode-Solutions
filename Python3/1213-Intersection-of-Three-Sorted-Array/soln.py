class Solution:
    def arraysIntersection(self, arr1: List[int], arr2: List[int], arr3: List[int]) -> List[int]:
        def isin(arr, num):
            idx = bisect.bisect_left(arr, num)
            return idx < len(arr) and arr[idx] == num
        ans = []
        for num in arr1:
            if isin(arr2, num) and isin(arr3, num):
                ans.append(num)
        return ans
