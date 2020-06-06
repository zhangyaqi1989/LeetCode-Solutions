class Solution:
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """
        counts = collections.Counter(tasks)
        m = counts.most_common(1)[0][1]
        mct = sum(cnt == m for cnt in counts.values())
        return max(len(tasks), (n + 1) * (m - 1) + mct)
