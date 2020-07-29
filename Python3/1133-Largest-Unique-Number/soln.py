class Solution:
    def largestUniqueNumber(self, A: List[int]) -> int:
        ans = -1
        counter = collections.Counter(A)
        for num, cnt in counter.items():
            if cnt == 1 and num > ans:
                ans = num
        return ans
