class Solution:
    def maxNumber(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
        n1, n2 = len(nums1), len(nums2)
        def pick(nums, k):
            ans = []
            r = len(nums) - k
            for num in nums:
                while ans and num > ans[-1] and r:
                    r -= 1
                    ans.pop()
                ans.append(num)
            return collections.deque(ans[:k])
        def merge(a, b):
            n = len(a) + len(b)
            return [max(a, b).popleft() for _ in range(n)]
        ans = []
        for i in range(k + 1):
            if i <= len(nums1) and k - i <= len(nums2):
                a = pick(nums1, i)
                b = pick(nums2, k - i)
                cur = merge(a, b)
                if cur > ans:
                    ans = cur
        return ans
