class Solution:
    def customSortString(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: str
        """
        counter = collections.Counter(T)
        ans = []
        for ch in S:
            ans += ch * counter[ch]
            if ch in counter:
                counter.pop(ch)
        return ''.join(ans) + ''.join([key * cnt for key, cnt in counter.items()])