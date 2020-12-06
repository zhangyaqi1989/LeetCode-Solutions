class Solution:
    def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
        sub = []
        n = len(nums)
        for i, num in enumerate(nums):
            while sub and num < sub[-1] and (n - i) + len(sub) > k:
                sub.pop()
            sub.append(num)
        return sub[:k]
