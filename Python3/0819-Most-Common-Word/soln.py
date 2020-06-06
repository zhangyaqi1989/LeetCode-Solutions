class Solution:
    def mostCommonWord(self, paragraph, banned):
        """
        :type paragraph: str
        :type banned: List[str]
        :rtype: str
        """
        return collections.Counter(word for word in re.sub("[!?',;.]", " ", paragraph).lower().split() if word not in banned).most_common(1)[0][0]