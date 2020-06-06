class Solution:
    def prefixesDivBy5(self, A: List[int]) -> List[bool]:
        ans = []
        num = 0
        for d in A:
            num = (num * 2 + d) % 5
            if num == 0:
                ans.append(True)
            else:
                ans.append(False)
        return ans
            
