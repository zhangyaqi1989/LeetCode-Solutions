class Solution:
    def peopleIndexes(self, favoriteCompanies: List[List[str]]) -> List[int]:
        # 500 * 100 * 100
        coms = {}
        idxes = []
        for i, lst in enumerate(favoriteCompanies):
            temp = set()
            for c in lst:
                if c not in coms:
                    coms[c] = len(coms)
                temp.add(coms[c])
            idxes.append(temp)
        n = len(idxes)
        ans = []
        for i, lst in enumerate(idxes):
            if not any(idxes[j] >= lst for j in range(n) if j != i):
                ans.append(i)
        return ans
