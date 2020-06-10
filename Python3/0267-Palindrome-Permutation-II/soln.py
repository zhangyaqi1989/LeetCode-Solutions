class Solution:
    def generatePalindromes(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        counts = collections.Counter(s)
        if sum(cnt & 1 == 1 for cnt in counts.values()) > 1:
            return []
        lefts = ''.join(ch * (cnt//2) for ch, cnt in counts.items())
        # permutation with duplicates
        lefts = sorted(lefts)
        mid = next((ch for ch in counts if counts[ch] & 1 == 1), '')
        half = [[]]
        for ch in lefts:
            half = [perm[:i] + [ch] + perm[i:] 
                    for perm in half
                    for i in range((perm + [ch]).index(ch) + 1)]
        return [''.join(l + [mid] + l[::-1]) for l in half]
