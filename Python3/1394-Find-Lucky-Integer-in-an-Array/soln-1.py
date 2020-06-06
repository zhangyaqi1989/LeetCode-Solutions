class Solution:
    def findLucky(self, arr: List[int]) -> int:
        counter = collections.Counter(arr)
        for num in sorted(counter, reverse=True):
            if num == counter[num]:
                return num
        return -1
