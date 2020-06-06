class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        window = collections.deque()
        ans = []
        for i, num in enumerate(nums):
            while window and num >= window[-1][0]:
                window.pop()
            window.append((num, i))
            if i - window[0][-1] > k - 1:
                window.popleft()
            if i >= k - 1:
                ans.append(window[0][0])
        return ans
