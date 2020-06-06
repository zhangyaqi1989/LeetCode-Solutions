class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        nxt = 1
        ans = []
        for num in target:
            while nxt != num:
                ans.append("Push")
                ans.append("Pop")
                nxt += 1
            ans.append("Push")
            nxt += 1
        return ans
