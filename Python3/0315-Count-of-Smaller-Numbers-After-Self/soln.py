class Solution:
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        def merge_sort(arr):
            n = len(arr)
            half = n // 2
            if half:
                left, right = merge_sort(arr[:half]), merge_sort(arr[half:])
                for i in reversed(range(n)):
                    if (not right) or (left and left[-1][1] > right[-1][1]):
                        smaller[left[-1][0]] += len(right)
                        arr[i] = left.pop()
                    else:
                        arr[i] = right.pop()
            return arr
        smaller = [0] * len(nums)
        merge_sort(list(enumerate(nums)))
        return smaller