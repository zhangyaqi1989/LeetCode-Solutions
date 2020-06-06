class Solution:
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        # tall first: the idea is the insert afterwards will not 
        # change the k
        ans = []
        for h, k in sorted(people, key=lambda x: (-x[0], x[1])):
            ans.insert(k, (h, k))
        return ans