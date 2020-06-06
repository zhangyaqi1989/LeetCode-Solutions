class TopVotedCandidate:

    def __init__(self, persons, times):
        """
        :type persons: List[int]
        :type times: List[int]
        """
        self.times = times[:]
        self.cands = []
        cand = persons[0]
        counter = collections.Counter()
        for person in persons:
            counter[person] += 1
            if counter[person] >= counter[cand]:
                cand = person
            self.cands.append(cand)

    def q(self, t):
        """
        :type t: int
        :rtype: int
        """
        return self.cands[bisect.bisect(self.times, t) - 1]
        


# Your TopVotedCandidate object will be instantiated and called as such:
# obj = TopVotedCandidate(persons, times)
# param_1 = obj.q(t)