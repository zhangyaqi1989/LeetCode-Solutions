class Solution:
    def intervalIntersection(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        idx = 0
        n = len(B)
        ans = []
        for sa, ea in A:
            while idx < n and B[idx][1] < sa:
                idx += 1
            while idx < n and B[idx][0] <= ea:
                sb, eb = B[idx]
                ans.append([max(sa, sb), min(ea, eb)])
                idx += 1
            if idx > 0:
                idx -= 1
        return ans
