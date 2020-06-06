class Solution:
    def wordSquares(self, words: List[str]) -> List[List[str]]:
        fulls = collections.defaultdict(list)
        n = len(words[0])
        for w in words:
            for i in range(1, n):
                fulls[w[:i]].append(w)
        def build(square):
            if len(square) == n:
                squares.append(square)
            else:
                # wall
                # area
                # le # need to find some startswith le
                nxt = ''.join(w[len(square)] for w in square)
                for word in fulls[nxt]:
                    build(square + [word])
        squares = []
        for word in words:
            build([word])
        return squares
