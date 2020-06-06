class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        A, B = 0, 0
        cntA, cntB = 0, 0
        ans = []
        for ch in seq:
            if ch == '(':
                if A <= B:
                    ans.append(0)
                    cntA += 1
                    A = max(A, cntA)
                else:
                    ans.append(1)
                    cntB += 1
                    B = max(B, cntB)
            else:
                if cntA >= cntB:
                    cntA -= 1
                    ans.append(0)
                else:
                    cntB -= 1
                    ans.append(1)
        return ans
