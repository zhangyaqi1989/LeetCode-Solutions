class Solution(object):
    def originalDigits(self, s):
        """
        :type s: str
        :rtype: str
        """
        counts = collections.Counter(s)
        res = [0] * 10
        res[0] = counts['z']
        res[2] = counts['w']
        res[4] = counts['u']
        res[6] = counts['x']
        res[8] = counts['g']
        res[3] = counts['h'] - res[8]
        res[7] = counts['s'] - res[6]
        res[5] = counts['v'] - res[7]
        res[1] = counts['o'] - (res[0] + res[2] + res[4])
        res[9] = (counts['n'] - (res[1] + res[7])) // 2
        return ''.join(str(i) * res[i] for i in range(10))
