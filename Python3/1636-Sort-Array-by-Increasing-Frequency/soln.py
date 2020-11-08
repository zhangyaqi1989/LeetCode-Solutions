class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        counter = collections.Counter(nums)
        pairs = list(counter.items())
        ans = []
        for key, cnt in sorted(pairs, key=lambda p: (p[1], -p[0])):
            ans.extend([key] * cnt)
        return ans
