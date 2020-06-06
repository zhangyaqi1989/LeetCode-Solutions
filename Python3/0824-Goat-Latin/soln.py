class Solution:
    def toGoatLatin(self, S):
        """
        :type S: str
        :rtype: str
        """
        ans = []
        for i, word in enumerate(S.split(), 1):
            if word[0] in 'AEIOUaeiou':
                ans.append(word + 'ma' + 'a' * i)
            else:
                ans.append(word[1:] + word[0] + 'ma' + 'a' * i)
        return ' '.join(ans)