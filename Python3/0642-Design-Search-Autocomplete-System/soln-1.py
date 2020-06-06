class TrieNode():
    def __init__(self):
        self.cnt = 0
        self.is_word = False
        self.children = collections.defaultdict(TrieNode)

class AutocompleteSystem:

    def __init__(self, sentences: List[str], times: List[int]):
        self.root = TrieNode()
        for sentence, cnt in zip(sentences, times):
            cur = self.root
            for ch in sentence:
                cur = cur.children[ch]
            cur.is_word = True
            cur.cnt += cnt
            
        self.user_input = ""
        self.cur = self.root
        
    def input(self, c: str) -> List[str]:
        if c == '#':
            cur = self.root
            for ch in self.user_input:
                cur = cur.children[ch]
            cur.is_word = True
            cur.cnt += 1
            self.cur = self.root
            self.user_input = ""
            return []
        else:
            self.user_input += c
            if self.cur:
                self.cur = self.cur.children.get(c)
            if self.cur is None:
                return []
            else:
                ans = []
                stack = [(self.cur, self.user_input)]
                while stack:
                    node, pre = stack.pop()
                    if node.is_word:
                        ans.append((-node.cnt, pre))
                    for ch, nei in node.children.items():
                        stack.append((nei, pre + ch))
                return [pre for _, pre in heapq.nsmallest(3, ans)]


# Your AutocompleteSystem object will be instantiated and called as such:
# obj = AutocompleteSystem(sentences, times)
# param_1 = obj.input(c)
