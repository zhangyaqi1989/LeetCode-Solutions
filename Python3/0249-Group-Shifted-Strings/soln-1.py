class Solution:
    def groupStrings(self, strings):
        """
        :type strings: List[str]
        :rtype: List[List[str]]
        """
        def shift(s):
            if not s:
                return s
            lst = list(s)
            diff = ord(lst[0])
            return ','.join(str(ord(ch) - diff + (0 if ord(ch) >= diff else 26)) for ch in lst)
        ans = collections.defaultdict(list)
        for s in strings:
            ans[shift(s)].append(s)
        return list(ans.values())