class Solution:
    def validSquare(self, p1, p2, p3, p4):
        """
        :type p1: List[int]
        :type p2: List[int]
        :type p3: List[int]
        :type p4: List[int]
        :rtype: bool
        """
        def dis(P, Q):
            "Return distance between two points."
            return sum((p - q) * (p - q) for p, q in zip(P, Q))
        d = {dis(P, Q) for P, Q in itertools.combinations((p1, p2, p3, p4), 2)}
        return len(d) == 2 and min(d) != 0 and max(d) // min(d) == 2
