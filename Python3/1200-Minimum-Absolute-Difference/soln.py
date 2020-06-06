class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        mn = math.inf
        ans = []
        arr.sort()
        n = len(arr)
        for i in range(n - 1):
            if arr[i + 1] - arr[i] < mn:
                mn = arr[i + 1] - arr[i]
                ans = [[arr[i], arr[i + 1]]]
            elif arr[i + 1] - arr[i] == mn:
                ans.append([arr[i], arr[i + 1]])
        return ans
