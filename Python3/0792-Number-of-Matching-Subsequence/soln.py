class Solution:
    def numMatchingSubseq(self, S, words):
        """
        :type S: str
        :type words: List[str]
        :rtype: int
        """
        # only traverse S once
        # how to update words when traverse S
        d = collections.defaultdict(list)
        for word in words:
            d[word[0]].append(word[1:])
        ans = 0
        for ch in S:
            if ch in d:
                lst = d.pop(ch)
                for item in lst:
                    if not item:
                        ans += 1
                    else:
                        d[item[0]].append(item[1:])
        return ans