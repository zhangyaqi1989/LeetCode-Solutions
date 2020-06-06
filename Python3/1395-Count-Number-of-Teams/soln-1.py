class Solution:
    def numTeams(self, rating: List[int]) -> int:
        n = len(rating)
        ans = 0
        for i in range(1, n):
            less, greater = [0] * 2, [0] * 2
            for j in range(n):
                if rating[i] < rating[j]:
                    less[j > i] += 1
                elif rating[i] > rating[j]:
                    greater[j > i] += 1
            ans += less[0] * greater[1] + less[1] * greater[0]
        return ans
