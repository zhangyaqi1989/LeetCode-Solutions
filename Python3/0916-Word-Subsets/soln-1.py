class Solution:
    def wordSubsets(self, A: List[str], B: List[str]) -> List[str]:
        bs = [0] * 26
        for word in B:
            temp = [0] * 26
            for ch in word:
                temp[ord(ch) - 97] += 1
            for i in range(26):
                bs[i] = max(bs[i], temp[i])
        def valid(word):
            temp = [0] * 26
            for ch in word:
                temp[ord(ch) - 97] += 1
            return all(temp[i] >= bs[i] for i in range(26))
        return [word for word in A if valid(word)]
