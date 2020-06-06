class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        tokens = text.split()
        n = len(tokens)
        ans = []
        for i in range(n - 2):
            if tokens[i] == first and tokens[i + 1] == second:
                ans.append(tokens[i + 2])
        return ans
        
