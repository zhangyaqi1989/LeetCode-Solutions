class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not words:
            return []
        nwords = len(words)
        counter = collections.Counter(words)
        ans = []
        m = len(words[0])
        total_len = nwords * m
        for i in range(len(s) - total_len + 1):
            seen = collections.Counter()
            j = i
            while j < i + total_len:
                word = s[j:j + m]
                if word in counter and seen[word] < counter[word]:
                    seen[word] += 1
                else:
                    break
                j += m
            else:
                ans.append(i)
        return ans
