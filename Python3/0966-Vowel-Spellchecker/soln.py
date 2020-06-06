class Solution:
    def spellchecker(self, wordlist, queries):
        """
        :type wordlist: List[str]
        :type queries: List[str]
        :rtype: List[str]
        """
        def encode(word):
            word = word.lower()
            return ''.join(['#' if ch in 'aeiou' else ch for ch in word])
        words = collections.defaultdict(list)
        wordset = set(wordlist)
        for word in wordlist:
            words[word.lower()].append(word)
            words[encode(word)].append(word)
        ans = []
        for query in queries:
            if query in wordset:
                ans.append(query)
            else:
                query = query.lower()
                if query in words:
                    ans.append(words[query][0])
                else:
                    encode_query = encode(query)
                    if encode_query in words:
                        ans.append(words[encode_query][0])
                    else:
                        ans.append('')
        return ans
