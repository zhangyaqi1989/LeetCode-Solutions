class Solution:
    def licenseKeyFormatting(self, S, K):
        """
        :type S: str
        :type K: int
        :rtype: str
        """
        S = S.replace('-', '').upper()
        num, first = divmod(len(S), K)
        return S[:first] + ('-' if first and first < len(S) else '') + '-'.join(S[i:i + K] for i in range(first, len(S), K))