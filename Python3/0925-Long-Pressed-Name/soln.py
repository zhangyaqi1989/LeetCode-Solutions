from itertools import zip_longest, groupby
class Solution:
    def isLongPressedName(self, name, typed):
        """
        :type name: str
        :type typed: str
        :rtype: bool
        """
        return all(ch1 == ch2 and len(list(g1)) <= len(list(g2)) for ((ch1, g1), (ch2, g2)) in zip_longest(groupby(name), groupby(typed), fillvalue=((1, None), (2, None))))