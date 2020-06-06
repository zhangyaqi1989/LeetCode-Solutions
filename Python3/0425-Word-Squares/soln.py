class Solution:
    def wordSquares(self, words):
        """
        :type words: List[str]
        :rtype: List[List[str]]
        """
        n = len(words[0])
        pres = collections.defaultdict(list)
        for word in words:
            for i in range(n):
                pres[word[:i]].append(word)
        def build(square):
            if len(square) == n:
                squares.append(square)
                return
            for word in pres[''.join(list(zip(*square))[len(square)])]:
                build(square + [word])
        squares = []
        for word in words:
            build([word])
        return squares