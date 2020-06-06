class Solution:
    def numTeams(self, rating: List[int]) -> int:
        n = len(rating)
        cnt = 0
        for i in range(n):
            for j in range(i + 1, n):
                if rating[j] == rating[i]:
                    continue
                # print(rating[i], rating[j])
                cond = rating[j] > rating[i]
                # print(cond)
                for k in range(j + 1, n):
                    if rating[j] == rating[k]:
                        continue
                    if cond == (rating[k] > rating[j]):
                        cnt += 1
        return cnt
