class Solution:
    def maskPII(self, S):
        """
        :type S: str
        :rtype: str
        """
        if '@' in S:
            first, rest = S.split('@')
            return '{}@{}'.format(first[0].lower() + '*' * 5 + first[-1].lower(), rest.lower())
        else:
            nums = [ch for ch in S if ch.isdigit()]
            if len(nums) == 10:
                return '***-***-{}'.format(''.join(nums[-4:]))
            else:
                return "+{}-***-***-{}".format('*' * (len(nums) - 10), ''.join(nums[-4:]))
