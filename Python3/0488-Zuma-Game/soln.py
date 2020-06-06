class Solution:
    def findMinStep(self, board, hand):
        """
        :type board: str
        :type hand: str
        :rtype: int
        """
        def helper(board, hand):
            if not board:
                return 0
            n = len(board)
            res = math.inf
            for m in re.finditer(r'R+|Y+|B+|G+|W+', board):
                s = m.start()
                e = m.end()
                need = max(0, 3 - (e - s))
                if hand[board[s]] >= need:
                    hand[board[s]] -= need
                    temp = helper(board[:s] + board[e:], hand)
                    res = min(temp + need, res);
                    hand[board[s]] += need
            return res
        ans = helper(board, collections.Counter(hand))
        return -1 if ans == math.inf else ans
