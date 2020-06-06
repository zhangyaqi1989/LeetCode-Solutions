class Solution:
    def rankTeams(self, votes: List[str]) -> str:
        ranks = collections.defaultdict(collections.Counter)
        for vote in votes:
            for i, ch in enumerate(vote):
                ranks[ch][i] += 1
        n = len(votes[0])
        def code(ch):
            ans = []
            for i in range(n):
                ans.append(-ranks[ch][i])
            ans.append(ord(ch))
            return ans
        chs = list(votes[0])
        chs.sort(key=code)
        return ''.join(chs)
