class Solution:
    def groupStrings(self, strings):
        """
        :type strings: List[str]
        :rtype: List[List[str]]
        """
        def shift(string):
            if not string:
                return string
            dis = ord(string[0]) - 97
            res = 'a'
            for ch in string[1:]:
                res += chr((ord(ch) - dis + 26) % 26)
            return res
        res = collections.defaultdict(list)
        for string in strings:
            res[shift(string)].append(string)
        return list(res.values())