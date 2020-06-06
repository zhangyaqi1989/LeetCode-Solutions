class Solution:
    def wordsAbbreviation(self, dict):
        """
        :type dict: List[str]
        :rtype: List[str]
        """
        def longest_common_prefix(word1, word2):
            cnt = 0
            for ch1, ch2 in zip(word1, word2):
                if ch1 == ch2:
                    cnt += 1
                else:
                    break
            return cnt
        ans = [None] * len(dict)
        groups = collections.defaultdict(list)
        for idx, word in enumerate(dict):
            groups['{}{}{}'.format(word[0], len(word) - 2, word[-1])].append((word, idx))
        for lst in groups.values():
            lst.sort()
            lcp = [0] * len(lst)
            for idx, (word, j) in enumerate(lst):
                if idx:
                    word1 = lst[idx - 1][0]
                    p = longest_common_prefix(word, word1)
                    lcp[idx] = max(lcp[idx], p)
                    lcp[idx - 1] = max(lcp[idx - 1], p)
            for (word, j), p in zip(lst, lcp):
                if len(word) - p - 2 > 1:
                    ans[j] = word[:p + 1] + str(len(word) - p - 2) + word[-1]
                else:
                    ans[j] = word
        return ans