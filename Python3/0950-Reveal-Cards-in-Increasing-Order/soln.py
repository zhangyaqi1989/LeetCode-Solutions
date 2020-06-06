class Solution:
    def deckRevealedIncreasing(self, deck):
        """
        :type deck: List[int]
        :rtype: List[int]
        """
        dq = collections.deque()
        for x in sorted(deck, reverse=True):
            if dq: dq.appendleft(dq.pop())
            dq.appendleft(x)
        return list(dq)