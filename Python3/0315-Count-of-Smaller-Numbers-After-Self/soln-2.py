class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        def merge_sort(pairs):
            n = len(pairs)
            half = n // 2
            if half:
                left, right = merge_sort(pairs[:half]), merge_sort(pairs[half:])
                for i in reversed(range(n)):
                    if not right or (left and left[-1][1] > right[-1][1]):
                        ans[left[-1][0]] += len(right)
                        pairs[i] = left.pop()
                    else:
                        pairs[i] = right.pop()
            return pairs
        ans = [0] * len(nums)
        merge_sort(list(enumerate(nums)))
        return ans
