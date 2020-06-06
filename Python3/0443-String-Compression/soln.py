class Solution:
    def compress(self, chars):
        """
        :type chars: List[str]
        :rtype: int
        """
        i = 0
        for key, group in itertools.groupby(chars):
            cnt = len(list(group))
            chars[i] = key
            i += 1
            if cnt > 1:
                cnt_s = str(cnt)
                chars[i:i + len(cnt_s)] = list(cnt_s)
                i += len(cnt_s)
        return i