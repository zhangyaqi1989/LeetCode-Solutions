import functools
class Solution:
    def maxProduct(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        words = [word for word in words if word]
        if not words:
            return 0
        def primes_gen():
            for num in itertools.count(2):
                if all(num % factor != 0 for factor in range(2, int(math.sqrt(num)) + 1)):
                    yield num
        primes = list(itertools.islice(primes_gen(), 26))
        codes = [functools.reduce(operator.mul, [primes[ord(ch) - 97] for ch in set(word)]) for word in words]
        ans = 0
        for i, j in itertools.combinations(range(len(words)), 2):
            if math.gcd(codes[i], codes[j]) == 1:
                ans = max(ans, len(words[i]) * len(words[j]))
        return ans
