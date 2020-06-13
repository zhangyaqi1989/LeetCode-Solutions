class Solution:
    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
        def compute_f(word):
            chars = [0] * 26
            for ch in word:
                chars[ord(ch) - ord('a')] += 1
            for i in range(26):
                if chars[i]:
                    return chars[i]
        freqs = [compute_f(word) for word in words]
        freqs.sort()
        ans = []
        for query in queries:
            f_query = compute_f(query)
            ans.append(len(freqs) - bisect.bisect_right(freqs, f_query))
        return ans
