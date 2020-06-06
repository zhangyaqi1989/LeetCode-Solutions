class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # [0, 1] take 1 before 0
        degrees = [0] * numCourses
        ans = []
        follows = collections.defaultdict(list)
        for course, req in prerequisites:
            degrees[course] += 1
            follows[req].append(course)
        frees = {i for i, d in enumerate(degrees) if d == 0}
        while frees:
            taken = frees.pop()
            ans.append(taken)
            for nei in follows[taken]:
                degrees[nei] -= 1
                if degrees[nei] == 0:
                    frees.add(nei)  
        return ans if len(ans) == numCourses else []
