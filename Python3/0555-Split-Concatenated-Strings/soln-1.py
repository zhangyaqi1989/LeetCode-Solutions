class Solution:
    def splitLoopedString(self, strs: List[str]) -> str:
        B = [max(item, item[::-1]) for item in strs]
        ans = ''.join(strs)
        start = ans[0]
        for i, token in enumerate(B):
            body = ''.join(B[i + 1:] + B[:i])
            for word in (token, token[::-1]):
                for j in range(len(word)):
                    if word[j] < start:
                        continue
                    else:
                        ans = max(ans, word[j:] + body + word[:j])
        return ans
