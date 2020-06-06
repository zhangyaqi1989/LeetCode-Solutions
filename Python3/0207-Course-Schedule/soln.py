class Solution:
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        pres, sucs = collections.defaultdict(set), collections.defaultdict(set)
        for a, b in prerequisites:
            pres[a].add(b)
            sucs[b].add(a)
        frees = set(range(numCourses)) - pres.keys()
        ans = []
        while frees:
            course = frees.pop()
            ans.append(course)
            if course in sucs:
                for nei in sucs.pop(course):
                    if len(pres[nei]) == 1:
                        pres.pop(nei)
                        frees.add(nei)
                    else:
                        pres[nei].remove(course)
        return len(ans) == numCourses