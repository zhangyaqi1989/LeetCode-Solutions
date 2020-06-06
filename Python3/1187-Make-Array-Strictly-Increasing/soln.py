class Solution:
    def makeArrayIncreasing(self, arr1: List[int], arr2: List[int]) -> int:
        arr2.sort()
        dp = {-1 : 0}
        for num in arr1:
            temp = {}
            for key in dp:
                if num > key:
                    temp[num] = min(temp.get(num, math.inf), dp[key])
                idx = bisect.bisect_right(arr2, key)
                if idx < len(arr2):
                    temp[arr2[idx]] = min(dp[key] + 1, temp.get(arr2[idx], math.inf))
            dp = temp
        if dp:
            return min(dp.values())
        return -1
