class Solution:
    def rearrangeBarcodes(self, packages: List[int]) -> List[int]:
        counter = collections.Counter(packages)
        n = len(packages)
        nums = []
        for num, cnt in counter.most_common():
            nums.extend([num] * cnt)
        idx = 0
        ans = [0] * n
        for i in range(0,n,2):
            ans[i] = nums[idx]
            idx += 1
        for j in range(1,n,2):
            ans[j] = nums[idx]
            idx += 1
        return ans
