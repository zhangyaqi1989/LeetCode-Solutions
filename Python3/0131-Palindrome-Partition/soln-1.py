class Solution:
    def partition(self, s: str) -> List[List[str]]:
        ans = []
        self.helper(s, 0, [], ans)
        return ans
        
    def isPalindrome(self, s):
        return s == s[::-1]
    
    def helper(self, s, idx, sub, ans):
        if idx == len(s):
            ans.append(sub[:])
        else:
            for i in range(idx + 1, len(s) + 1):
                if self.isPalindrome(s[idx : i]):
                    sub.append(s[idx : i])
                    self.helper(s, i, sub, ans)
                    sub.pop()
        
