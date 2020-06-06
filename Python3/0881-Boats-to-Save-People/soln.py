class Solution:
    def numRescueBoats(self, people, limit):
        """
        :type people: List[int]
        :type limit: int
        :rtype: int
        """
        people.sort()
        l, r, cnt = 0, len(people) - 1, 0
        saved = 0
        while saved < len(people):
            if people[r] + people[l] <= limit:
                l += 1
                saved += 1
            r -= 1
            saved += 1
            cnt += 1
        return cnt