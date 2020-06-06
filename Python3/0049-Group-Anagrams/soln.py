import functools
class Solution:
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101]
        ans = collections.defaultdict(list)
        for string in strs:
            if not string:
                ans[0].append(string)
            else:
                ans[functools.reduce(operator.mul, [primes[ord(ch) - 97] for ch in string])].append(string)
        return list(ans.values())