class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        # have the same length
        if not s or not any(words) or len(s) < len(words[0]) * len(words):
            return []
        words_count = collections.Counter(map(tuple, words))
        def check(i, l, word_len):
            cur = collections.Counter()
            iters = [iter(s[i:i + l])] * word_len
            for word in zip(*iters):
                cur[word] += 1
                if cur[word] > words_count[word]:
                    return False
            return True
        word_len, k = len(words[0]), len(words)
        l = word_len * k
        return [i for i in range(len(s) + 1 - l) if check(i, l, word_len)]