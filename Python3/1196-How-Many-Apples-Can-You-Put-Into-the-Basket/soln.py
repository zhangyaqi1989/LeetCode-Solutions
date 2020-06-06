class Solution:
    def maxNumberOfApples(self, arr: List[int]) -> int:
        basket = 0
        cnt = 0
        for num in sorted(arr):
            if basket + num <= 5000:
                basket += num
                cnt += 1
        return cnt
