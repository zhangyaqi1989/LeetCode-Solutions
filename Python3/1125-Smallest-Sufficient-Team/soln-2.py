class Solution:
    def smallestSufficientTeam(self, req_skills: List[str], people: List[List[str]]) -> List[int]:
        n = len(req_skills)
        dst = (1 << n) - 1
        skills = {skill : i for i, skill in enumerate(req_skills)}
        m = len(people)
        ps = []
        for lst in people:
            state = 0
            for s in lst:
                state |= (1 << skills[s])
            ps.append(state)
        frontier = [(0, 0)]
        levels = {0 : 0}
        step = 0
        while frontier:
            nxt_level = []
            for state, p in frontier:
                if state == dst:
                    ans = []
                    for i in range(m):
                        if p & (1 << i):
                            ans.append(i)
                    return ans
                for i in range(m):
                    if (p & (1 << i)) == 0:
                        new_state = state | ps[i]
                        np = p | (1 << i)
                        if new_state not in levels:
                            levels[new_state] = step + 1
                            nxt_level.append((new_state, np))
            frontier = nxt_level
            step += 1
