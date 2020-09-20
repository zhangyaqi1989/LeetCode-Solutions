class Solution:
    def reorderSpaces(self, text: str) -> str:
        nspaces = text.count(' ')
        words = text.strip().split()
        nwords = len(words)
        delim = ' ' * (nspaces // (nwords - 1) if nwords != 1 else 0)
        ans = delim.join(words)
        return ans + ' ' * (nspaces % (nwords - 1) if nwords != 1 else nspaces)
