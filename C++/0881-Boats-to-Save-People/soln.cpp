class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
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
};
