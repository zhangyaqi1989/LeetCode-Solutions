class Solution:
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        ans = []
        self.helper([], ans, 0, s)
        return ans
        
    def helper(self, path, ans, i, s):
        if len(path) == 3:
            if i < len(s) and self.valid(s[i:]):
                path.append(s[i:])
                ans.append('.'.join(path))
        else:
            if i < len(s):
                for j in range(i + 1, min(i + 4, len(s))):
                    if self.valid(s[i:j]):
                        self.helper(path + [s[i:j]], ans, j, s)
                    
    def valid(self, sub):
        num = int(sub)
        return not (num > 255 or (len(sub) > 1 and sub[0] == '0'))
