class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        lo, hi = 0, len(people) - 1
        cnt = 0
        people.sort()
        while lo <= hi:
            if people[hi] + people[lo] <= limit:
                hi -= 1
                lo += 1
            else:
                hi -= 1
            cnt += 1
        return cnt
