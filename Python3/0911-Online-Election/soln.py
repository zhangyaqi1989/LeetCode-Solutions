class TopVotedCandidate:

    def __init__(self, persons, times):
        """
        :type persons: List[int]
        :type times: List[int]
        """
        self.times = times
        cand = persons[0]
        counter = collections.Counter()
        self.cands = []
        for time, person in zip(times, persons):
            counter[person] += 1
            if counter[person] >= counter[cand]:
                cand = person
            self.cands.append(cand)

    def q(self, t):
        """
        :type t: int
        :rtype: int
        """
        idx = bisect.bisect_right(self.times, t)
        return self.cands[idx - 1]



# Your TopVotedCandidate object will be instantiated and called as such:
# obj = TopVotedCandidate(persons, times)
# param_1 = obj.q(t)
