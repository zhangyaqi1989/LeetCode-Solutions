import functools
class Solution:
    def wordSubsets(self, A, B):
        """
        :type A: List[str]
        :type B: List[str]
        :rtype: List[str]
        """
        primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101]
        def encode(word):
            return functools.reduce(operator.mul, [primes[ord(ch) - 97] for ch in word])
        bs = [encode(word) for word in B]
        bs = list(set(bs))
        def universal(word):
            code = encode(word)
            return all(code % b == 0 for b in bs)
        return list(filter(universal, A))