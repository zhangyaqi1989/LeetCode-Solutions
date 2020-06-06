class Solution:
    def isNStraightHand(self, hand, W):
        """
        :type hand: List[int]
        :type W: int
        :rtype: bool
        """
        counter = collections.Counter(hand)
        for key in sorted(counter):
            if counter[key] > 0:
                for j in reversed(range(W)):
                    counter[key + j] -= counter[key]
                    if counter[key + j] < 0:
                        return False
        return True