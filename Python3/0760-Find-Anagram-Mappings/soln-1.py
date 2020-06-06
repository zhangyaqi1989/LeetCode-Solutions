class Solution:
    def anagramMappings(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        # anagram map: linear
        d = collections.defaultdict(list)
        for j, num in enumerate(B):
            d[num].append(j)
        return [d[num].pop() for num in A]