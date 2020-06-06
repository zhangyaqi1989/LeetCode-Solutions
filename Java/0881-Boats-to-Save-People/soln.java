class Solution {
    public int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people);
        int n = people.length;
        int lo = 0, hi = n - 1, cnt = 0;
        while (lo <= hi) {
            if (people[hi] + people[lo] <= limit) {
                --hi;
                ++lo;
            } else {
                --hi;
            }
            ++cnt;
        }
        return cnt;
    }
}
