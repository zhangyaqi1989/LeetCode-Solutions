class Solution:
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        if len(s2) < len(s1): return False
        counter1 = collections.Counter(s1)
        n1 = len(s1)
        counter2 = collections.Counter(s2[:len(s1)])
        for i in range(n1, len(s2)):
            if counter2 == counter1:
                return True
            counter2[s2[i]] += 1
            counter2[s2[i - n1]] -= 1
            if counter2[s2[i - n1]] == 0:
                counter2.pop(s2[i - n1])
        return counter2 == counter1