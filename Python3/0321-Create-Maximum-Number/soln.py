class Solution:
    def maxNumber(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[int]
        """
        def mx_array(nums, k):
            "Pick k digits of nums to create max number with order preserved."
            drop = len(nums) - k
            out  = []
            for num in nums:
                while drop and out and out[-1] < num:
                    drop -= 1
                    out.pop()
                out.append(num)
            return collections.deque(out[:k])
        
        def merge(a, b):
            "Merge two array of digits."
            return [max(a, b).popleft() for _ in a + b]

        return max(merge(mx_array(nums1, i), mx_array(nums2, k - i))
                   for i in range(k + 1)
                   if i <= len(nums1) and k - i <= len(nums2))
