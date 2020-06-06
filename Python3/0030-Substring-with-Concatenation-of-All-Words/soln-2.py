class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not words:
            return []
        n = len(words)
        m = len(words[0])
        counter = collections.Counter(words)
        ans = []
        for i in range(len(s)):
            if i + m * n > len(s):
                break
            window = collections.Counter()
            start = i
            for j in range(n):
                w = s[start:start + m]
                cnt = window[w]
                window[w] = cnt + 1
                if cnt + 1 > counter[w]:
                    break
                start += m
            else:
                ans.append(i)
        return ans
