class Solution:
    def findLucky(self, arr: List[int]) -> int:
        counter = collections.Counter(arr)
        ans = -1
        for num in sorted(counter):
            if num == counter[num]:
                ans = num
        return ans
