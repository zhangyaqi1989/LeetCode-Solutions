class Solution:
    def numSubarraysWithSum(self, A, S):
        """
        :type A: List[int]
        :type S: int
        :rtype: int
        """
        acc_dic = collections.Counter()
        acc_dic[0] += 1
        res, acc = 0, 0
        for num in A:
            acc += num
            res += acc_dic[acc - S]
            acc_dic[acc] += 1
        return res