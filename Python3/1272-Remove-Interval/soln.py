class Solution:
    def removeInterval(self, intervals: List[List[int]], toBeRemoved: List[int]) -> List[List[int]]:
        ans = []
        rs, re = toBeRemoved
        for s, e in intervals:
            if e <= rs:
                ans.append([s, e])
            elif s >= re:
                ans.append([s, e])
            else:
                if s < max(s, rs):
                    ans.append([s, max(s, rs)])
                if e > min(e, re):
                    ans.append([min(e, re), e])
        return ans
