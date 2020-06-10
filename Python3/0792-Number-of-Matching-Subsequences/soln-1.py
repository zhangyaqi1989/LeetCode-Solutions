class Solution:
    def numMatchingSubseq(self, S, words):
        """
        :type S: str
        :type words: List[str]
        :rtype: int
        """
        d = collections.defaultdict(list)
        for word in words:
            d[word[0]].append(word[1:])
        cnt = 0
        for ch in S:
            if ch in d:
                for item in d.pop(ch):
                    if len(item) == 0:
                        cnt += 1
                    else:
                        d[item[0]].append(item[1:])
        return cnt