class Solution:
    def partition(self, s: str) -> List[List[str]]:
        ans = []
        self.helper(s, 0, [], ans)
        return ans
        
    def helper(self, s, idx, partition, ans):
        if idx == len(s):
            ans.append(partition[:])
        else:
            for end in range(idx + 1, len(s) + 1):
                nxt = s[idx:end]
                if nxt == nxt[::-1]:
                    partition.append(nxt)
                    self.helper(s, end, partition, ans)
                    partition.pop()
        
