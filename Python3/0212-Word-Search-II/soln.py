class TrieNode():
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.is_word = False

class Solution:
    def findWords(self, board, words):
        """
        :type board: List[List[str]]
        :type words: List[str]
        :rtype: List[str]
        """
        if not any(board):
            return []
        root = TrieNode()
        for word in words:
            cur = root
            for ch in word:
                cur = cur.children[ch]
            cur.is_word = True
        ans = set()
        def dfs(i, j, cur, sub, ans):
            if cur.is_word:
                ans.add(sub)
                # return # do not return here
            if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]):
                return
            if not used[i][j] and cur.children.get(board[i][j], None) != None:
                used[i][j] = 1
                dfs(i - 1, j, cur.children[board[i][j]], sub+board[i][j], ans)
                dfs(i + 1, j, cur.children[board[i][j]], sub+board[i][j], ans)
                dfs(i, j - 1, cur.children[board[i][j]], sub+board[i][j], ans)
                dfs(i, j + 1, cur.children[board[i][j]], sub+board[i][j], ans)
                used[i][j] = 0
        m, n = len(board), len(board[0])
        used = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                dfs(i, j, root, '', ans)
        return list(ans)