class Solution:
    def smallestSufficientTeam(self, req_skills: List[str], people: List[List[str]]) -> List[int]:
        needed = {skill : i for i, skill in enumerate(req_skills)}
        n = len(needed)
        dp = {i : list(range(len(people))) for i in range(1 << n)}
        dp[0] = []
        for i, lst in enumerate(people):
            temp = 0
            for item in lst:
                if item in needed:
                    temp |= (1 << needed[item])
            for skill_hash, value in dp.items():
                if (skill_hash | temp) == skill_hash:
                    continue
                if len(dp[skill_hash | temp]) > len(value) + 1:
                    dp[skill_hash | temp] = value + [i]
        return dp[(1 << n) - 1]
