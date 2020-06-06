class TrieNode:
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.is_word = False
        
class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        # check if its prefix exists
        folder.sort(key=lambda x : len(x))
        root = TrieNode()
        ans = []
        for path in folder:
            cur = root
            for name in path.split('/'):
                if not name:
                    continue
                cur = cur.children[name]
                if cur.is_word:
                    break
            else:
                cur.is_word = True
                ans.append(path)
        return ans
