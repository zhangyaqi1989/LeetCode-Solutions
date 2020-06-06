class Solution:
    def numRescueBoats(self, people, limit):
        """
        :type people: List[int]
        :type limit: int
        :rtype: int
        """
        # gurrenteed that each person can carried by a boat
        people.sort()
        l, r = 0, len(people) - 1
        cnt = 0
        while l <= r:
            if people[l] + people[r] <= limit:
                l, r = l + 1, r - 1
            else:
                r -= 1
            cnt += 1
        return cnt