class Solution:
    def wordPatternMatch(self, pattern, string):
        """
        :type pattern: str
        :type string: str
        :rtype: bool
        """
        if pattern is None or string is None:
            return False
        if len(string) < len(pattern):
            return False
        return self.dfs(pattern, string, 0, 0, {})
        
    def dfs(self, pattern, string, i, j, dic):
        if i == len(pattern) and j == len(string):
            return True
        if i == len(pattern) or j == len(string):
            return False
        if pattern[i] in dic:
            length = len(dic[pattern[i]])
            if dic[pattern[i]] == string[j:j + length]:
                return self.dfs(pattern, string, i + 1, j + length, dic)
            else:
                return False
        else:
            for length in range(1, (len(string) - j) - (len(pattern) - i) + 2):
                if string[j:j+length] in dic.values():
                    continue
                dic[pattern[i]] = string[j:j+length]
                if self.dfs(pattern, string, i + 1, j + length, dic):
                    return True
                del dic[pattern[i]]
        return False