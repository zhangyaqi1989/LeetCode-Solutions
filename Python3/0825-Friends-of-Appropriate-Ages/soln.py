class Solution:
    def numFriendRequests(self, ages):
        """
        :type ages: List[int]
        :rtype: int
        """
        def request(A, B):
            "Check if A will friend request B."
            return B > 0.5 * A + 7 and B <= A
        counts = collections.Counter(ages)
        return sum(counts[a] * (counts[b] - (a == b)) for a in counts for b in counts if request(a, b))
