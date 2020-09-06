class Solution:
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
        n = len(arr)
        # [1, 2, 3, 10, 4, 2, 3, 5]
        left = [-math.inf]
        for i in range(n):
            if arr[i] >= left[-1]:
                left.append(arr[i])
            else:
                break
        if len(left) == n + 1:
            return 0
        right = [math.inf]
        for j in range(n - 1, -1, -1):
            if arr[j] <= right[-1]:
                right.append(arr[j])
            else:
                break
        right = right[::-1]
        ans = n - 1
        for i in range(len(left)):
            mx = left[i]
            idx = bisect.bisect_left(right, mx)
            cnt = i + len(right) - idx - 1
            ans = min(ans, n - cnt)
        return ans
