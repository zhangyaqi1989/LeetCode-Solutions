class Solution:
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        pres, sucs = collections.defaultdict(set), collections.defaultdict(set)
        for suc, pre in prerequisites:
            pres[suc].add(pre)
            sucs[pre].add(suc)
        frees = set(range(numCourses)) - pres.keys()
        ans = []
        while frees:
            course = frees.pop()
            ans.append(course)
            if course in sucs: # free its suc
                for nei in sucs.pop(course):
                    if len(pres[nei]) == 1:
                        frees.add(nei)
                        pres.pop(nei)
                    elif len(pres[nei]) > 1:
                        pres[nei].remove(course)
        return ans if len(ans) == numCourses else []
        