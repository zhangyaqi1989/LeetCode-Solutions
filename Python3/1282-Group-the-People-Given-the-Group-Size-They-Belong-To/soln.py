class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        groups = collections.defaultdict(list)
        ans = []
        for i, sz in enumerate(groupSizes):
            groups[sz].append(i)
            if len(groups[sz]) == sz:
                ans.append(groups[sz][:])
                groups[sz].clear()
        return ans
