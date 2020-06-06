class Solution(object):
    def findReplaceString(self, S, indexes, sources, targets):
        """
        :type S: str
        :type indexes: List[int]
        :type sources: List[str]
        :type targets: List[str]
        :rtype: str
        """
        finds = [S[idx:idx + len(source)] == source for idx, source in zip(indexes, sources)]
        diff = 0
        S = list(S)
        for idx, find, source, target in sorted(zip(indexes, finds, sources, targets)):
            if find:
                S[idx + diff : idx + diff + len(source)] = list(target)
                diff += len(target) - len(source)
        return ''.join(S)