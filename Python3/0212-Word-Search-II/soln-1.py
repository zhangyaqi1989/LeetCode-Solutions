class TrieNode:
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.is_word = False

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        root = TrieNode()
        for word in words:
            cur = root
            for ch in word:
                cur = cur.children[ch]
            cur.is_word = True
        ans = []
        def dfs(cur, path, i, j):
            if cur.is_word:
                ans.append(path)
                cur.is_word = False
            if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]) or board[i][j] == '#' or cur.children.get(board[i][j]) == None:
                    return
            ch = board[i][j]
            board[i][j] = '#'
            new_cur = cur.children[ch]
            dfs(new_cur, path + ch, i - 1, j)
            dfs(new_cur, path + ch, i + 1, j)
            dfs(new_cur, path + ch, i, j - 1)
            dfs(new_cur, path + ch, i, j + 1)
            board[i][j] = ch
        for i in range(len(board)):
            for j in range(len(board[0])):
                dfs(root, "", i, j)
        return ans
